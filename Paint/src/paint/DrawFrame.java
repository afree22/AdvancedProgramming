package paint;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import java.awt.event.ItemListener;
import java.util.LinkedList;
import java.awt.event.ItemEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.FlowLayout;
import java.awt.Color;

/*
 * Provides the GUI and encapsulates the DrawPanel
 * It creates 3 buttons save, load, and clear.
 * It creates 2 combobox colors and shapes.
 * Has two private inner classes 
 * One for handling button events
 * Another for handling both combo box events and checkbox events
 */
public class DrawFrame extends JFrame
{
	private LinkedList<Shape> myShapes;
    private DrawPanel panel; //draw panel for the shapes
    private JButton save; // button to undo last drawn shape
    private JButton load; // button to redo an undo
    private JButton reset; // button to reset panel
    private JComboBox colors; //combobox with color options

    //array of strings containing color options for JComboBox colors
    private String colorOptions[]=
    {"Black","Blue", "Green", "Magenta","Orange","Pink","Red","Yellow"};
    
    //aray of Color objects contating Color constants
    private Color colorArray[]=
    {Color.BLACK, Color.BLUE, Color.GREEN, Color.MAGENTA, Color.ORANGE ,Color.PINK , Color.RED , Color.YELLOW};
    
    private JComboBox shapes; //combobox with shape options
    
    //array of strings containing shape options for JComboBox shapes
    private String shapeOptions[]=
    {"Draw Line","Draw Rectangle","Draw Oval", "Draw Triangle","Insert Text"};
    
    //private JCheckBox filled; //checkbox to select whether shape is filled or not
        
    private JPanel widgetJPanel; //holds the widgets: buttons, comboboxes and checkbox
    private JPanel widgetPadder; //encapsulates widgetJPanel and adds padding around the edges 
    
    /**
     * This constructor sets the name of the JFrame.
     * It also creates a DrawPanel object that extends JPanel for drawing the shapes and contains
     * a statuslabel for mouse position.
     * Initializes widgets for buttons, comboboxes and checkbox
     * It also adds event handlers for the widgets
     */
    public JComboBox getColors() {return colors;}
    public JComboBox getShapes() {return shapes;}
    public Color[] getColorArray() {return colorArray;}
    public String[] getColorOptions() {return colorOptions;}


    
    public DrawFrame(LinkedList<Shape> shapeslist)
    {
        super("Paint Project"); //sets the name of DrawFrame
        
        myShapes = shapeslist; //initialize myShapes
        
        JLabel statusLabel = new JLabel( "" ); //create JLabel object to pass into DrawPanel
        
        panel = new DrawPanel(statusLabel, myShapes); //create draw panel and pass in JLabel and ShapesList
        
        //create buttons
        save = new JButton( "Save" ); //previously undo
        load = new JButton( "Load File" ); //previously redo
        reset = new JButton( "Reset" );
        
        //create comboboxes
        colors = new JComboBox( colorOptions );
        shapes = new JComboBox( shapeOptions );
        
        //JPanel object, widgetJPanel, with grid layout for widgets
        widgetJPanel = new JPanel();
        widgetJPanel.setLayout( new GridLayout( 1, 6, 10, 10 ) ); //sets padding between widgets in gridlayout
        
        //JPanel object, widgetPadder, with flowlayout to encapsulate and pad the widgetJPanel
        widgetPadder = new JPanel();
        widgetPadder.setLayout(new FlowLayout(FlowLayout.LEADING, 20, 5)); //sets padding around the edges
            
        // add widgets to widgetJPanel
        widgetJPanel.add(save );
        widgetJPanel.add( load );
        widgetJPanel.add( reset);
        widgetJPanel.add( colors );
        widgetJPanel.add( shapes );  
        
        
        //widgetJPanel.add( filled );
        // add widgetJPanel to widgetPadder
        widgetPadder.add( widgetJPanel );
        
        //add widgetPadder and panel to JFrame
        add( widgetPadder, BorderLayout.NORTH);
        add( panel, BorderLayout.CENTER);
        
        // create new ButtonHandler for button event handling
        ButtonHandler buttonHandler = new ButtonHandler();
        save.addActionListener( buttonHandler );
        load.addActionListener( buttonHandler );
        reset.addActionListener( buttonHandler );
        
        //create handlers for combobox and checkbox
        ItemListenerHandler handler = new ItemListenerHandler();
        colors.addItemListener( handler );
        shapes.addItemListener( handler );
        
        setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        pack();
        setSize( 900, 700 );
        setVisible( true );
        
        
    } // end DrawFrame constructor
    
	public JButton getReset() {
		return reset;
	}

	public JButton getSave() {
		return save;
	}

	public JButton getLoad() {
		return load;
	}
	
    public LinkedList<Shape> getMyShapes(){return myShapes;}
    public DrawPanel getPanel() {return panel;}
   
    

    /**
     * private inner class for button event handling
     */
    private class ButtonHandler implements ActionListener
    {
        // handles button events
        public void actionPerformed( ActionEvent event )
        {
            if (event.getActionCommand().equals("Save")){
                //panel.clearLastShape();
            }
            else if (event.getActionCommand().equals("Load")){
                //panel.redoLastShape();
            }
            else if (event.getActionCommand().equals("Reset")){
                panel.clearDrawing();
            }
             
        } // end method actionPerformed
    } // end private inner class ButtonHandler
    
    /**
     * private inner class for checkbox and combobox event handling
     */
    private class ItemListenerHandler implements ItemListener
    {
        public void itemStateChanged( ItemEvent event )
        {
            // determine whether combo box selected
            if ( event.getStateChange() == ItemEvent.SELECTED )
            {
                //if event source is combo box colors pass in colorArray at index selected.
                if ( event.getSource() == colors)
                {
                    panel.setCurrentShapeColor
                        (colorArray[colors.getSelectedIndex()]);
                }
                
                //else if event source is combo box shapes pass in index selected
                else if ( event.getSource() == shapes)
                {
                    panel.setCurrentShapeType(shapes.getSelectedIndex());
                    //System.out.println("You have selected shape: " + shapes.getSelectedIndex());
                }
            }
            
        } // end method itemStateChanged
    }
    
} // end class DrawFrame