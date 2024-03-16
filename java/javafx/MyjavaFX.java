import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

public class MyjavaFX extends Application {
	@override
	public void start(Stage primaryStage) {
		Button btOk = new Button("OK");
		Scene scene = new Scene(byOk, 200, 250);
		primaryStage.setTitile("MyjavaFX");
		primaryStage.setScene(scene);
		primaryStage.show();
	}

	public static void main(String[] args) {
		Application.launch(args);
	}
}