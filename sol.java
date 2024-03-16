import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.Border;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class TicTacToe extends Application {
    private char whoseTrun = 'X';
    private Cell[][] cells = new Cell[3][3];
    private Label lblStatus = new Label("X's turn to play");

    @java.lang.Override
    public void start(Stage stage) throws Exception {
        GridPane pane = new GridPane();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                pane.add(new Cell(), j, i);// GridPane的add方法是先列后行
            }
        }
        Button button = new Button("再来一局");
        BorderPane borderPaneForButton = new BorderPane();// 上中左右下五种位置的布局
        borderPaneForButton.setCenter(lblStatus);// 先弄一个布局把当前谁的回合放在中间
        borderPaneForButton.setRight(button);// 再来一句的按钮放在布局的右边
        lblStatus.setPadding(new Insets(5));// 控件与边界的距离
        BorderPane borderPane = new BorderPane();
        borderPane.setCenter(pane);
        borderPane.setBottom(borderPaneForButton);// 然后把回合信息和按键的布局放在下方，BorderPane套BorderPane
        Scene scene = new Scene(borderPane, 500, 500);
        stage.setScene(scene);
        stage.show();
    }

    public boolean isWon(char token) {
        // 行
        for (int i = 0; i < 3; i++) {
            int cnt = 0;
            for (int j = 0; j < 3; j++) {
                if (cells[i][j].getToken() == token)
                    cnt++;
            }
            if (cnt == 3)
                return true;
        }
        // 列
        for (int j = 0; j < 3; j++) {
            int cnt = 0;
            for (int i = 0; i < 3; i++) {
                if (cells[i][j].getToken() == token)
                    cnt++;
                if (cnt == 3)
                    return true;
            }
        }
        char a = cells[0][0].getToken();
        char b = cells[1][1].getToken();
        char c = cells[2][2].getToken();
        if (a == b && b == c)
            return true;
        a = cells[0][2].getToken();
        c = cells[2][0].getToken();
        if (b == c && a == c)
            return true;
        return false;
    }

    public boolean isFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cells[i][j].getToken() == ' ')
                    return false;
            }
        }
        return true;
    }

    public class Cell extends Pane {
        private char token = ' ';

        public Cell() {
            this.setStyle(" -fx-border-color: black");
            this.setPrefSize(2000, 2000);
            this.setOnMouseClicked(event -> handleMouseClick());
        }

        public char getToken() {
            return token;
        }

        public void setToken(char c) {
            token = c;
            if (token == 'X') {
                // pane的坐标原点在左上角
                Line line1 = new Line(10, 10, this.getWidth() - 10, this.getHeight() - 10);// 起始坐标和结束坐标
                line1.endXProperty().bind(this.widthProperty().subtract(10));
                line1.endYProperty().bind(this.heightProperty().subtract(10));
                Line line2 = new Line(this.getWidth() - 10, 10, 10, this.getHeight() - 10);// 起始坐标和结束坐标
                line2.endXProperty().bind(this.widthProperty().subtract(10));
                line2.endYProperty().bind(this.heightProperty().subtract(10));
                this.getChildren().addAll(line1, line2);
            } else if (token == 'O') {
                Ellipse ellipse = new Ellipse(this.getWidth() / 2, this.getHeight() / 2, this.getWidth() / 2 - 10,
                        this.getHeight() / 2 - 10);// 中心位置，长轴和短轴
                ellipse.centerXProperty().bind(this.widthProperty().divide(2));
                ellipse.centerYProperty().bind(this.heightProperty().divide(2));
                ellipse.radiusXProperty().bind(this.widthProperty().divide(2));
                ellipse.radiusYProperty().bind(this.heightProperty().divide(2));
                ellipse.setStroke(Color.BLACK);
                ellipse.setFill(Color.GREEN);
                this.getChildren().addAll(ellipse);
            }
        }

        private void handleMouseClick() {
            if (this.token == ' ' && whoseTrun != ' ') {
                this.setToken(whoseTrun);
            }
            if (isWon(whoseTrun)) {
                lblStatus.setText(whoseTrun + " won! The game is over!");
            } else if (isFull()) {
                lblStatus.setText("Draw! The game is over!");
            } else {
                whoseTrun = (whoseTrun == 'O' ? 'X' : 'O');
                lblStatus.setText(whoseTrun + "'s turn");
            }
        }
    }
}