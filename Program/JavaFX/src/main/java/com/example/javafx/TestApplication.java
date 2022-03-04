package com.example.javafx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class TestApplication extends Application{
    @Override
    public void start(Stage stage) throws Exception{
//        stage.setTitle("myTest");

        TestGridPanel panel = new TestGridPanel();
        Scene scene = new Scene(panel);
        stage.setScene(scene);
        stage.sizeToScene();
        stage.show();
    }
}
