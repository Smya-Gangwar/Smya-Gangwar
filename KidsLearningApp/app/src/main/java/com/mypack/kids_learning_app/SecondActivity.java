package com.mypack.kids_learning_app;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.content.Intent;
import android.widget.Button;
import android.view.View;
public class SecondActivity extends AppCompatActivity
{
    Button butt1,butt2,butt3,butt4,butt5,butt6;
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        butt1=(Button)findViewById(R.id.btn1);
        butt1.setOnClickListener(new View.OnClickListener(){
                                   @Override
                                   public void onClick(View v)
                                   {
                                       Intent intent = new Intent(getBaseContext(),Flags.class);
                                       startActivity(intent);
                                   }
                               }
        );
        butt2=(Button)findViewById(R.id.btn2);
        butt2.setOnClickListener(new View.OnClickListener(){
                                     @Override
                                     public void onClick(View v)
                                     {
                                         Intent intent = new Intent(getBaseContext(),Colors.class);
                                         startActivity(intent);
                                     }
                                 }
        );
        butt3=(Button)findViewById(R.id.btn3);
        butt3.setOnClickListener(new View.OnClickListener(){
                                     @Override
                                     public void onClick(View v)
                                     {
                                         Intent intent = new Intent(getBaseContext(),Symbols.class);
                                         startActivity(intent);
                                     }
                                 }
        );
        butt4=(Button)findViewById(R.id.btn4);
        butt4.setOnClickListener(new View.OnClickListener(){
                                     @Override
                                     public void onClick(View v)
                                     {
                                         Intent intent = new Intent(getBaseContext(),Alphabets.class);
                                         startActivity(intent);
                                     }
                                 }
        );
        butt5=(Button)findViewById(R.id.btn5);
        butt5.setOnClickListener(new View.OnClickListener(){
                                     @Override
                                     public void onClick(View v)
                                     {
                                         Intent intent = new Intent(getBaseContext(),Fruits.class);
                                         startActivity(intent);
                                     }
                                 }
        );
        butt6=(Button)findViewById(R.id.btn6);
        butt6.setOnClickListener(new View.OnClickListener(){
                                     @Override
                                     public void onClick(View v)
                                     {
                                         Intent intent = new Intent(getBaseContext(),Vegetables.class);
                                         startActivity(intent);
                                     }
                                 }
        );
    }
}
