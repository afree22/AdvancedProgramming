package paint;

import java.awt.Color;
import java.awt.Graphics;

public class Rectangle extends Shape {

	public int rShapeType = 1;

	public Rectangle(int xa, int ya, int xb, int yb, Color col) {
		setShapeType(rShapeType);
		setX1(xa);
		setY1(ya);
		setX2(xb);
		setY2(yb);
		setColor(col);

	}

	// gets the upper left x
	public int getUpperLeftX() {
		return Math.min(getX1(), getX2());
	}

	// gets the upper left y
	public int getUpperLeftY() {
		return Math.min(getY1(), getY2());
	}

	// gets width
	public int getWidth() {
		return Math.abs(getX1() - getX2());
	}

	// gets height
	public int getHeight() {
		return Math.abs(getY1() - getY2());
	}

	@Override
	public void draw(Graphics g) {
		g.setColor(getColor()); // sets the color
		g.fillRect(getUpperLeftX(), getUpperLeftY(), getWidth(), getHeight());
		// //draws a filled rectangle

	}

}
