package paint;

import java.awt.Color;
import java.awt.Graphics;

abstract class Shape {
	private Color color;
	private String colorString;
	private int shapeType;
	private int x1, y1, x2, y2; // coordinates of shape
	private int x3, y3; // unused unless triangle

	// setter and getter for color
	public Color getColor() {
		return color;
	}

	public void setColor(Color c) {
		color = c;
	}

	public String getColorString(Color c) {
		String color = null;
		if (c == Color.BLACK) {
			color = "black";
		} else if (c == Color.BLUE) {
			color = "blue";
		} else if (c == Color.GREEN) {
			color = "green";
		} else if (c == Color.MAGENTA) {
			color = "magneta";
		} else if (c == Color.ORANGE) {
			color = "orange";
		} else if (c == Color.PINK) {
			color = "pink";
		} else if (c == Color.RED) {
			color = "red";
		} else if (c == Color.YELLOW) {
			color = "yellow";
		}
		return color;
	}

	// setter and getter for shapeType
	public int getShapeType() {
		return shapeType;
		// 0 for Line, 1 for Rectangle, 2 for Oval
		// 3 for triangle and 4 for text
	}

	public void setShapeType(int s) {
		shapeType = s;
	}

	// setters for coordinates of shape
	public void setX1(int x1) {
		this.x1 = x1;
	}

	public void setY1(int y1) {
		this.y1 = y1;
	}

	public void setX2(int x2) {
		this.x2 = x2;
	}

	public void setY2(int y2) {
		this.y2 = y2;
	}

	public void setX3(int x3) {
		this.x3 = x3;
	}

	public void setY3(int y3) {
		this.y3 = y3;
	}

	public int getX1() {
		return x1;
	}

	//
	// Getters for coordinates of shape
	//
	public int getY1() {
		return y1;
	}

	public int getX2() {
		return x2;
	}

	public int getY2() {
		return y2;
	}

	public int getX3() {
		return x3;
	}

	public int getY3() {
		return y3;
	}

	// abstract function to be overridden in inherited classes
	abstract public void draw(Graphics g);

}
