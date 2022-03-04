package com.example.javafx;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.FlowPane;

import java.text.SimpleDateFormat;
import java.util.Date;

public class PanelDate extends FlowPane {
    Button button;
    Label label;

    SimpleDateFormat formatter;
    Date date;
    public PanelDate(){
        button = new Button("mis a jour ");
        formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
        date = new Date();
        label = new Label(formatter.format(date));

        button.setOnAction((event) -> {
            date = new Date();
            label.setText(formatter.format(date));
        });

        this.getChildren().addAll(button, label);
    }
}
