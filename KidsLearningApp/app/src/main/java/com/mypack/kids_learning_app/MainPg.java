package com.mypack.kids_learning_app;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.content.Intent;
import android.widget.Button;
import android.view.View;

public class MainPg extends AppCompatActivity
{
    Button butt1,butt2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_pg);
        butt1 = (Button) findViewById(R.id.btn1);
        butt1.setOnClickListener(new View.OnClickListener() {
                                     @Override
                                     public void onClick(View v) {
                                         Intent intent = new Intent(getBaseContext(), SecondActivity.class);
                                         startActivity(intent);
                                     }
                                 }
        );
        butt2 = (Button) findViewById(R.id.btn2);
        butt2.setOnClickListener(new View.OnClickListener() {
                                     @Override
                                     public void onClick(View v) {
                                         Intent intent = new Intent(getBaseContext(), Developer.class);
                                         startActivity(intent);
                                     }
                                 }
        );
    }
}
