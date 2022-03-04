package com.example.javafx;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;

public class PanelColor extends FlowPane {
    Button buttonGreen;
    Button buttonBlue;
    Label label;

    public PanelColor(){
        buttonBlue = new Button("Color Blue ");
        buttonGreen = new Button("Color Green ");
        label = new Label();

        buttonGreen.setOnAction((event) -> {
            label.setTextFill(Color.GREEN);
        });

        buttonGreen.setOnAction((event) -> {
            label.setTextFill(Color.GREEN);
        });

        this.getChildren().addAll(buttonGreen, buttonBlue, label);
    }
}
