package paint;

import java.awt.Color;
import java.awt.Graphics;

public class Line extends Shape {

	private int lShapeType = 0;

	public Line(int xa, int ya, int xb, int yb, Color col) {
		setShapeType(lShapeType);
		setX1(xa);
		setY1(ya);
		setX2(xb);
		setY2(yb);
		setColor(col);

	}

	@Override
	public void draw(Graphics g) {
		g.setColor(getColor()); // sets the color
		g.drawLine(getX1(), getY1(), getX2(), getY2()); // draws the line

	}

}
