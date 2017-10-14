package paint;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JOptionPane;

public class Text extends Shape {

	private String message;
	private int txtShapeType = 4;

	public void setMessage(String m) {
		message = m;
	}

	public String getMessage() {
		return message;
	}

	public Text(int xa, int ya, Color col, String m) {
		setShapeType(txtShapeType);
		setX1(xa);
		setY1(ya);
		setColor(col);
		message = m;
	}

	@Override
	public void draw(Graphics g) {

		g.setColor(getColor()); // sets the color
		g.drawString(message, getX1(), getY1());

	}

}
