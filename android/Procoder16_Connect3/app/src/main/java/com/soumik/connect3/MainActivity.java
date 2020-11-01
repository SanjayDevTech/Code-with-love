package com.soumik.connect3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import androidx.gridlayout.widget.GridLayout;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    //0=yellow,1=red,2=empty

    int activePlayer=0;
    int[] gameState={2,2,2,2,2,2,2,2,2};
    int[][] winningPositions={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{2,4,6},{0,4,8}};
    boolean gameActive=true;

    public void dropIn(View view){

        ImageView counter=(ImageView)view;

        int tappedCounter=Integer.parseInt(counter.getTag().toString());

        if(gameState[tappedCounter]==2 && gameActive){

        gameState[tappedCounter]=activePlayer;
        counter.setTranslationY(-1500);

        if(activePlayer==0){
        counter.setImageResource(R.drawable.yellow);
        activePlayer=1;
        }
        else{
            counter.setImageResource(R.drawable.red);
            activePlayer=0;
        }

        counter.animate().translationYBy(1500).rotation(1800).setDuration(600);

        for(int winningPosition[]:winningPositions) {
            if (gameState[winningPosition[0]] == gameState[winningPosition[1]] && gameState[winningPosition[1]] == gameState[winningPosition[2]] && gameState[winningPosition[0]] != 2) {
                //Someone has won!!!!
                gameActive=false;
                String winner;
                if (activePlayer == 1) {
                    winner = "Yellow";
                } else {
                    winner = "Red";
                }

                Button playAgainButton=(Button)findViewById(R.id.playAgainButton);
                TextView winnerText=(TextView) findViewById(R.id.winnerTextView);
                winnerText.setText(winner + " has won!!");
                winnerText.setVisibility(View.VISIBLE);
                playAgainButton.setVisibility(View.VISIBLE);
            }
        }
        }
    }

        public void playAgain(View view){

        Button playAgainButton=(Button)findViewById(R.id.playAgainButton);
        TextView winnerText=(TextView) findViewById(R.id.winnerTextView);
        winnerText.setVisibility(View.INVISIBLE);
        playAgainButton.setVisibility(View.INVISIBLE);

        GridLayout gridLayout=(GridLayout)findViewById(R.id.gridLayout);
        for(int i=0;i<gridLayout.getChildCount();i++){
            ImageView counter = (ImageView)gridLayout.getChildAt(i);
            counter.setImageDrawable(null);
        }
        for (int i=0;i<gameState.length;i++){
            gameState[i]=2;
        }
        gameActive=true;
        activePlayer=0;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}