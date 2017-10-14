package paint;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.NoSuchElementException;

import javax.swing.JButton;

public class ButtonHandler implements ActionListener {
	private DrawPanel panel;
	private LinkedList<Shape> myShapes;
	private ArrayList<Shape> shapeArray;
	private String[] colorOptions;
	private JButton save, reset, load;

	public ButtonHandler(DrawFrame frame) // needs access to ControllerUI
	{
		// using the getter functions from ControllerUI
		// to set values for variables
		panel = frame.getPanel();
		myShapes = frame.getMyShapes();
		colorOptions = frame.getColorOptions();
		save = frame.getSave();
		reset = frame.getReset();
		load = frame.getLoad();
	}

	// handles button events
	public void actionPerformed(ActionEvent event) {
		if(event.getSource() == save) {
			try {
				saveFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} else if (event.getSource() == load) {
			loadFile();
		} else if (event.getSource() == reset) {
			// clears linked list by calling makeEmpty in DrawPanel
			panel.clearDrawing();

		}

	} // end method actionPerformed



	public void saveFile() throws IOException {
		File fout = new File("temp.txt");
		FileOutputStream fos = new FileOutputStream(fout);

		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));

//		for (int counter = shapeArray.size() - 1; counter >= 0; counter--) {
//			Shape tmp = shapeArray.get(counter);
//			bw.write(Integer.toString(tmp.getShapeType()));
//
//			Color shapeColor = tmp.getColor();
//			bw.write(tmp.getColorString(shapeColor));
			
			
			  Iterator<Shape> it = myShapes.iterator();
			  while ( it.hasNext() )
			  {
				  Shape s = it.next();
				  bw.write(Integer.toString(s.getShapeType()));
				  Color shapeColor = s.getColor();
				  bw.write(s.getColorString(shapeColor));
				 
			  }
			// have successfully written shape type and index of color
			// must write the coordinates
				bw.close();
		}

	
//	}

	public void loadFile() {

		String filename = "temp.txt"; // The name of the file to open.
		String line; // used to read in lines from file

		try {
			// open the file
			File f = new File(filename);
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);

			int val = 0;
			int j = 0;

			line = br.readLine();
			while (line != null) {
				// get first character
				// create shape object according to value of first character
				// set the color and the coordinates of the shape object
				val = Integer.parseInt("" + line.charAt(j));
				line = br.readLine();
				j++;
			}

			br.close();
			drawTheBoard();

		}

		catch (FileNotFoundException ex) {
			System.out.println("Unable to open file '" + filename + "'");
		} catch (IOException ex) {
			System.out.println("Error reading file '" + filename + "'");
			// Or we could just do this:
			// ex.printStackTrace();
		} catch (NoSuchElementException n) {
		}
	}

	public void drawTheBoard() {
		// draw the shapes

		for (int counter = shapeArray.size() - 1; counter >= 0; counter--)
			shapeArray.get(counter).draw(null);
	}

	public int getIndex(ArrayList<Shape> sa, Color c) {

		int k = 0;
		for (int i = 0; i < sa.size(); i++) {
			Shape tmp = shapeArray.get(i);
			if (tmp.getColor() == c) {
				k = i;
				break;
			}
		}
		return k;
	}

} // end private inner class ButtonHandler