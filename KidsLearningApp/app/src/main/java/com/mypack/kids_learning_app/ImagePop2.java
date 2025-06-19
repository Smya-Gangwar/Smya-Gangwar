package com.mypack.kids_learning_app;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import androidx.appcompat.app.AppCompatActivity;

public class ImagePop2 extends AppCompatActivity {

        Button btn;
        int imgID;
        ImageView i;

        @Override
        protected void onCreate(Bundle savedInstanceState)
        {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.imgpop);
            Intent intent=getIntent();
            imgID=intent.getIntExtra("Img",0);
            i=(ImageView)findViewById(R.id.icon);
            i.setImageResource(imgID);
            btn=(Button)findViewById(R.id.butt);
            btn.setOnClickListener(new View.OnClickListener(){
                @Override
                public void onClick(View v)
                {
                    Intent intent = new Intent(getBaseContext(),Flags.class);
                    startActivity(intent);
                }
            });

        }
    }
