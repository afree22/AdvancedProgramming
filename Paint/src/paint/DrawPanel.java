package paint;

import java.awt.Color;

import java.awt.Graphics;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.BorderLayout;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;
import java.util.LinkedList;
import java.util.Iterator;

/**
 * This class handles mouse events and uses them to draw shapes. It contains a
 * dynamic stack myShapes which is the shapes drawn on the panel. It has many
 * variables for the current shape [type, variable to store shape object, color,
 * fill]. It contains a JLabel called statusLabel for the mouse coordinates It
 * has mutator methods for currentShapeType, currentShapeColor and
 * currentShapeFilled. It has methods for undoing, redoing and clearing shapes.
 * It has a private inner class MouseHandler which extends MouseAdapter and
 * handles mouse and mouse motion events used for drawing the current shape.
 */

public class DrawPanel extends JPanel {
	private LinkedList<Shape> myShapes; // ShapesList instance

	// current Shape variables
	private int currentShapeType; // 0 for line, 1 for rect, 2 for oval, 3 for triangle, 4 for text
	private Shape currentShapeObject; // stores the current shape object
	private Color currentShapeColor; // current shape color

	/**
	 * This constructor initializes myShapes. It sets the current shape variables to
	 * default values. It initalizes statusLabel from JLabel passed in. Sets up the
	 * panel and adds event handling for mouse events.
	 */
	public DrawPanel(JLabel statusLabel, LinkedList<Shape> shapesList) {

		myShapes = shapesList; // initialize myShapes

		// Initialize current Shape variables
		currentShapeType = 0;
		currentShapeObject = null;
		currentShapeColor = Color.BLACK;

		setLayout(new BorderLayout()); // sets layout to border layout; default is flow layout
		setBackground(Color.WHITE); // sets background color of panel to white
		add(statusLabel, BorderLayout.SOUTH); // adds a statuslabel to the south border

		// event handling for mouse and mouse motion events
		MouseHandler handler = new MouseHandler();
		addMouseListener(handler);
		addMouseMotionListener(handler);
	}

	/*
	 * Calls the draw method for the existing shapes.
	 */
	public void paintComponent(Graphics g) {
		super.paintComponent(g);

		// draw the shapes
		int i = 0;
		while (i < myShapes.size()) {
			myShapes.get(i).draw(getGraphics());
			i++;
		}

		// Iterator<Shape> it = myShapes.iterator();
		// while ( it.next() != null )
		// {
		// Shape s = it.next();
		// s.draw(null);
		// }

		// draws the current Shape Object if it is not null
		if (currentShapeObject != null)
			currentShapeObject.draw(getGraphics());
	}

	// Mutator methods for currentShapeType, currentShapeColor and
	// currentShapeFilled

	/*
	 * Sets the currentShapeType to type (0 for line, 1 for rect, 2 for oval, 3 for
	 * triangle or 4 for text) passed in.
	 */
	public void setCurrentShapeType(int type) {
		currentShapeType = type;
	}

	/*
	 * Sets the currentShapeColor to the Color object passed in. The Color object
	 * contains the color for the current shape.
	 */
	public void setCurrentShapeColor(Color color) {
		currentShapeColor = color;
	}

	/**
	 * Remove all shapes in current drawing. Also makes clearedShapes empty since
	 * you cannot redo after clear. It called repaint() to redraw the panel.
	 */
	public void clearDrawing() {
		Iterator<Shape> it = myShapes.iterator();
		while (it != null) {
			myShapes.removeLast();
		}
		repaint();
	}

	public LinkedList<Shape> getMyShapes() {
		return myShapes;
	}

	/**
	 * Private inner class that implements MouseAdapter and does event handling for
	 * mouse events.
	 */
	private class MouseHandler extends MouseAdapter {
		/**
		 * When mouse is pressed draw a shape object based on type, color and filled.
		 * X1,Y1 & X2,Y2 coordinate for the drawn shape are both set to the same X & Y
		 * mouse position.
		 */
		int pX1 = 0;
		int pX2 = 0;
		int pX3 = 0;
		int pY1 = 0;
		int pY2 = 0;
		int pY3 = 0;
		Boolean pointExists1 = false;
		Boolean pointExists2 = false;

		// use for the shapes that are created by dragging -- line, rectangle, and oval
		public void mousePressed(MouseEvent event) {

			switch (currentShapeType) // 0 for line, 1 for rect, 2 for oval
			{
			case 0:
				currentShapeObject = new Line(event.getX(), event.getY(), event.getX(), event.getY(),
						currentShapeColor);
				break;
			case 1:
				currentShapeObject = new Rectangle(event.getX(), event.getY(), event.getX(), event.getY(),
						currentShapeColor);
				break;
			case 2:
				currentShapeObject = new Oval(event.getX(), event.getY(), event.getX(), event.getY(),
						currentShapeColor);
				break;

			}
		} // end method mousePressed

		// Use method to handle shapes that are created by clicking:
		// applies to the triangle and text
		public void mouseClicked(MouseEvent event) {

			switch (currentShapeType) // 0 for line, 1 for rect, 2 for oval
			{

			case 3: // Triangle
				if (pointExists1 == false) {
					pX1 = event.getX();
					pY1 = event.getY();
					pointExists1 = true;
				} else if (pointExists2 == false) {
					pX2 = event.getX();
					pY2 = event.getY();
					pointExists2 = true;
				} else {
					pX3 = event.getX();
					pY3 = event.getY();
					currentShapeObject = new Triangle(pX1, pY1, pX2, pY2, pX3, pY3, currentShapeColor);
					myShapes.addFirst(currentShapeObject);
					currentShapeObject = null;
					repaint();
					pointExists1 = pointExists2 = false;
				}
				break;

			case 4: // Text
				String mssge = JOptionPane.showInputDialog("enter text to display");
				pX1 = event.getX();
				pY1 = event.getY();
				currentShapeObject = new Text(pX1, pY1, currentShapeColor, mssge);
				myShapes.addFirst(currentShapeObject);
				currentShapeObject = null;
				repaint();
				break;

			}// end switch case
		} // end method mousePressed

		/**
		 * When mouse is released set currentShapeObject's x2 & y2 to mouse pos. Then
		 * addFront currentShapeObject onto the myShapes dynamic Stack and set
		 * currentShapeObject to null [clearing current shape object since it has been
		 * drawn].
		 */

		// Used with shapes that require dragging -- not used for triangle or text
		// Function gets the released position of mouse and sends it to the shape then
		// it adds
		// the shape to the list and repaints the board
		public void mouseReleased(MouseEvent event) {

			if (currentShapeType == 0 || currentShapeType == 1 || currentShapeType == 2) {
				// sets currentShapeObject x2 & Y2
				currentShapeObject.setX2(event.getX());
				currentShapeObject.setY2(event.getY());

				myShapes.addFirst(currentShapeObject); // addFront currentShapeObject onto myShapes

				currentShapeObject = null; // sets currentShapeObject to null
				repaint();
			}

		} // end method mouseReleased

		/*
		 * This method gets the mouse position when it is dragging and sets x2 & y2 of
		 * current shape to the mouse pos It also gets the mouse position when it is
		 * dragging and sets it to statusLabel Then it calls repaint() to redraw the
		 * panel
		 */
		public void mouseDragged(MouseEvent event) {

			// The triangle and text do not respond to the mouse dragging when they are
			// created
			if (currentShapeType == 0 || currentShapeType == 1 || currentShapeType == 2) {
				// sets currentShapeObject x2 & Y2
				currentShapeObject.setX2(event.getX());
				currentShapeObject.setY2(event.getY());
				// sets statusLabel to current mouse position

				repaint();
			}
		}

	}// end MouseHandler

} // end class DrawPanel