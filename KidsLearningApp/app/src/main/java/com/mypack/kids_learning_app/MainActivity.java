package com.mypack.kids_learning_app;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.view.View;
import android.widget.Button;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity
{
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn=(Button)findViewById(R.id.button1);
        btn.setOnClickListener(new View.OnClickListener(){
                                   @Override
                                   public void onClick(View v)
                                   {
                                       Intent intent = new Intent(getBaseContext(),MainPg.class);
                                       startActivity(intent);
                                   }
                               }
        );
    }
}