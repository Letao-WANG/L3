package com.example.javafx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class ColorApplication extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        stage.setTitle("Color Application");

        Pane myPane = new PanelColor();
        Scene scene = new Scene(myPane);
        stage.setScene(scene);
        stage.sizeToScene();
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
