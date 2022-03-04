package com.example.javafx;

import javafx.geometry.Orientation;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;

public class TestSmallPanel extends FlowPane {
    TextField textField;
    TextArea textArea;

    public TestSmallPanel(){
        this.setOrientation(Orientation.VERTICAL);
        textField = new TextField();
        textArea = new TextArea();
        textArea.setPrefRowCount(10);

        this.getChildren().addAll(textField, textArea);
    }
}
