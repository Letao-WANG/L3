package com.example.javafx;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;

public class TestPanel extends BorderPane {
    Button button1;
    Label label1;
    Label label2;
    TestSmallPanel smallPanel;


    public TestPanel(){
        button1 = new Button("button1");
        label1 = new Label("label1");
        label2 = new Label("label2");
        smallPanel = new TestSmallPanel();

        button1.setOnAction((event)->{
            label1.setTextFill(Color.RED);
        });

        this.setCenter(button1);
        this.setLeft(label1);
        this.setBottom(label2);

        this.setRight(smallPanel);
//        this.getChildren().addAll(button1, label1);
    }
}
