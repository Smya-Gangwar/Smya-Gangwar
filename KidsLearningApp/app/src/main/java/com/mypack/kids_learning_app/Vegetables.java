package com.mypack.kids_learning_app;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Button;
public class Vegetables extends AppCompatActivity
{
    ListView list;
    String[] vegesList = {"Beet Root","Bitter Gourd","Bottle Gourd","Brinjal","Cabbage","Capsicum","Carrot",
				"Cauli Flower","Cluster Beans","Corn","Cucumber","Garlic","Ginger",
				"Lady's Finger","Mushroom","Onion","Potato","Radish","Red Chilli","Tomato"};
    int[] img ={R.drawable.beetroot,R.drawable.bittergourd,R.drawable.bottlegourd,R.drawable.brinjal,
		R.drawable.cabbage,R.drawable.capsicum,R.drawable.carrot,R.drawable.cauliflower,
		R.drawable.clusterbeans,R.drawable.corn,R.drawable.cucumber,R.drawable.garlic,
		R.drawable.ginger,R.drawable.ladysfinger,R.drawable.mushroom,R.drawable.onion,R.drawable.potato,
		R.drawable.radish,R.drawable.redchilli,R.drawable.tomato};
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.flags);
        list = (ListView)findViewById(R.id.list1);
        CustomAdapter cust = new CustomAdapter(this,vegesList,img);
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
                Intent intent = new Intent(getBaseContext(), ImagePop5.class);
                intent.putExtra("Img",img[position]);
                startActivity(intent);
            }
        });
    }
}

