package com.mypack.kids_learning_app;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Button;

public class Colors extends AppCompatActivity
{
    ListView list;
    String[] colorList = {"Black","Brown","White","Dark Blue","Light Blue",
			"Dark Green","Light Green","Gray","Orange","Pink",
			"Purple","Red","Yellow"};
    int[] img = {R.drawable.black,R.drawable.brown,R.drawable.white,
		R.drawable.darkblue,R.drawable.lightblue,R.drawable.darkgreen,
		R.drawable.lighgreen,R.drawable.gray,R.drawable.orange,
		R.drawable.pink,R.drawable.purple,R.drawable.red,
		R.drawable.yellow};
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.flags);
        list = (ListView)findViewById(R.id.list1);
        CustomAdapter cust = new CustomAdapter(this,colorList,img);
        list.setAdapter(cust);
        btn=(Button)findViewById(R.id.butt);
        btn.setOnClickListener(new View.OnClickListener(){
                                     @Override
                                     public void onClick(View v)
                                     {
                                         Intent intent = new Intent(getBaseContext(),SecondActivity.class);
                                         startActivity(intent);
                                     }
                                 });
        list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent intent = new Intent(getBaseContext(), ImagePop3.class);
                intent.putExtra("Img",img[position]);
                startActivity(intent);
            }
        });
    }
}

