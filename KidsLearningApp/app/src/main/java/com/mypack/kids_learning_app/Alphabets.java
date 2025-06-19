package com.mypack.kids_learning_app;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Button;

public class Alphabets extends AppCompatActivity
{
    ListView list;
    String[] alphaList = {"A - Apple","B - Bee","C - Cat","D - Dog",
			"E - Elephant","F - Fish","G - Goat","H - Hat",
			"I - Igloo","J - Jar","K - Kite","L - Lion",
			"M - Mouse","N - Nest","O - Octopus","P - Pig",
			"Q - Quilt","R - Robot","S - Snake","T - Turtle",
			"U - Umbrella","V - Violin","W - Wheelcart","X - X-Ray",
			"Y - Yarn","Z - Zebra"};
    int[] img ={R.drawable.a,R.drawable.b,R.drawable.c,R.drawable.d,
		R.drawable.e,R.drawable.f,R.drawable.g,R.drawable.h,
		R.drawable.i,R.drawable.j,R.drawable.k,R.drawable.l,
		R.drawable.m,R.drawable.n,R.drawable.o,R.drawable.p,
		R.drawable.q,R.drawable.r,R.drawable.s,R.drawable.t,
		R.drawable.u,R.drawable.v,R.drawable.w,R.drawable.x,
		R.drawable.y,R.drawable.z};
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.flags);
        list = (ListView)findViewById(R.id.list1);
        CustomAdapter cust = new CustomAdapter(this,alphaList,img);
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
                Intent intent = new Intent(getBaseContext(), ImagePop4.class);
                intent.putExtra("Img",img[position]);
                startActivity(intent);
            }
        });
    }
}

