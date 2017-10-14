package paint;

import java.awt.Color;
import java.awt.Graphics;

public class Triangle extends Shape {

	public int tShapeType = 3;

	// TODO write constructor for Triangle
	
	public Triangle(int xa, int ya, int xb, int yb, int xc, int yc, Color col) {
		setShapeType(tShapeType);
		setX1(xa);
		setY1(ya);
		setX2(xb);
		setY2(yb);
		setX3(xc);
		setY3(yc);
		setColor(col);
	}

	@Override
	public void draw(Graphics g) {
		g.setColor(getColor()); // sets the color
		g.drawPolygon(new int[] { getX1(), getX2(), getX3() }, new int[] { getY1(), getY2(), getY3() }, 3);
		System.out.println("In the draw function for trangle");

	}

}