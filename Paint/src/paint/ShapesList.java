package paint;

import java.util.*;
import java.util.LinkedList;
import java.util.Iterator;


public class ShapesList 

{
		DrawFrame frame;
	   LinkedList<Shape> myShapes; // attribute, once class is created it exists, can be 
	                                 // used later
	   
	   // constructor, reads a file of shapes and loads them onto the list
	   // and does a report() to check list contents
	   public ShapesList()
	   {
		   myShapes = new LinkedList<Shape> (); // initialize the list
		   frame =  new DrawFrame(myShapes);
	   }
	   
	   public static void main( String[] args )
	   {
		  
		   new ShapesList();//start DrawFrame  
	   }
	   
	   // Process this line from the file, expecting shapes
	   // definitions ...
	   // Note: catch errors in line (so you can keep reading the file)
	   
	   // print out about all of the shapes on the list
	   public void report()
	   {
		  Iterator<Shape> it = myShapes.iterator();
		  while ( it.hasNext() )
		  {
			 Shape s = it.next();
		  }
	   }
	   public void draw()
	   {
		   
	   }

	}
