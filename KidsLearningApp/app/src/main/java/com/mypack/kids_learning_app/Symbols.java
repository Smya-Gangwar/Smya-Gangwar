package com.mypack.kids_learning_app;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Button;
public class Symbols extends AppCompatActivity
{
    ListView list;
    String[] symbolList = {"Father of the Nation - Mahatma Gandhi","Mother India",
			"Currency - Indian Rupee","National Emblem","National Flag - Tiranga",
			"National Animal - Tiger","National Aquatic Animal - Dolphin",
			"National Bird - Peacock","National Flower - Lotus","National Fruit - Mango",
			"National Game - Hockey","National River - Ganga",
			"National Tree - Banyan Tree","National Anthem","National Song"};
    int[] img ={R.drawable.fatherofthenation,R.drawable.motherindia,R.drawable.indianrupee,
		R.drawable.nationalemblem,R.drawable.nationalflag,R.drawable.nationalanimal,
		R.drawable.nationalaquaticanimal,R.drawable.nationalbird,R.drawable.nationalflower,
		R.drawable.nationalfruit,R.drawable.nationalgame,R.drawable.nationalriver,
		R.drawable.nationaltree,R.drawable.nationalanthem,R.drawable.nationalsong};
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.flags);
        list = (ListView)findViewById(R.id.list1);
        CustomAdapter cust = new CustomAdapter(this,symbolList,img);
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
                Intent intent = new Intent(getBaseContext(), ImagePop6.class);
                intent.putExtra("Img",img[position]);
                startActivity(intent);
            }
        });
    }
}

