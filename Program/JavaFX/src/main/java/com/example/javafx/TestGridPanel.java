package com.example.javafx;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;

public class TestGridPanel extends GridPane {

    TextField textField1;
    TextField textField2;
    Label label1;

    Button btuAddition;
    Button btuSubtraction;
    Button btuReset;

    public TestGridPanel(){
        textField1 = new TextField();
//        textField1.setPrefColumnCount(5);
        textField2 = new TextField();
//        textField2.setPrefColumnCount(10);
        label1 = new Label();

        btuAddition = new Button("+");
        btuSubtraction = new Button("-");
        btuReset = new Button("Reset");

        btuAddition.setOnAction((event)->{
           label1.setText(Integer.toString(Integer.valueOf(textField1.getText())+Integer.valueOf(textField2.getText())));
        });

        btuSubtraction.setOnAction((event)->{
            label1.setText(Integer.toString(Integer.valueOf(textField1.getText())-Integer.valueOf(textField2.getText())));
        });

        btuReset.setOnAction((event)->{
           label1.setText("");
        });

        this.addRow(0, textField1, textField2, label1);
        this.addRow(1, btuAddition, btuSubtraction, btuReset);

    }

}
