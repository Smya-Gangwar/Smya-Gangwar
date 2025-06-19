package com.mypack.kids_learning_app;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Button;
public class Fruits extends AppCompatActivity
{
    ListView list;
    String[] fruitList = {"Apple","Banana","Grapes","Lemon","Mango","Orange","Papaya","Pineapple","Strawberry","SugarApple",
				"Watermelon"};
    int[] img = {R.drawable.apple,R.drawable.banana,R.drawable.grapes,R.drawable.lemon,R.drawable.mango,R.drawable.orangef,
            R.drawable.papaya,R.drawable.pineapple,R.drawable.strawberry,R.drawable.sugarapple,
            R.drawable.watermelon};
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.flags);
        list = (ListView)findViewById(R.id.list1);
        CustomAdapter cust = new CustomAdapter(this,fruitList,img);
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
                    Intent intent = new Intent(getBaseContext(), ImagePop.class);
                    intent.putExtra("Img",img[position]);
                    startActivity(intent);
            }
        });
    }

}

