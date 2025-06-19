package com.mypack.kids_learning_app;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Button;
public class Flags extends AppCompatActivity
{
    ListView list;
    String[] countryList = {"India","Argentina","Australia","Austria","Belgium","Bolivia","Brazil","Canada","Chile","China","Colombia",
                            "Congo","Cuba","Denmark","Egypt","European Union","Finland","France","Georgia","Germany","Ghana","Greece",
                            "Guana","Hungary","Iceland","Indonesia","Ireland","Israel","Italy","Japan","Kazakhistan","Kuwait","Liberia",
                            "Luxemberg","Netherlands","Nigeria","North Korea","Norway","Peru","Phillipines","Poland","Portugal","Quatar",
                            "RAN","RAQ","Russia","Saudi Arabia","Scotland","South Africa","Sudan","Sweden","Switzerland","Syria","Thailand",
                            "Turkey","Ukraine","United Arab Emirates","United Kingdome","USA","Venezuela","Vetnam"};
    int[] flags = {R.drawable.india,R.drawable.argentina,R.drawable.australia,R.drawable.austria,R.drawable.belgium,
                    R.drawable.bolivia,R.drawable.brazil,R.drawable.canada,R.drawable.chile,R.drawable.china,R.drawable.colombia,
                    R.drawable.congo,R.drawable.cuba,R.drawable.denmark,R.drawable.egypt,R.drawable.europeanunion,R.drawable.finland,
                    R.drawable.france,R.drawable.georgia,R.drawable.germany,R.drawable.ghana,R.drawable.greece,R.drawable.guana,
                    R.drawable.hungary,R.drawable.iceland,R.drawable.indonesia,R.drawable.ireland,R.drawable.israel,R.drawable.italy,
                    R.drawable.japan,R.drawable.kazakhistan,R.drawable.kuwait,R.drawable.liberia,R.drawable.luxemberg,R.drawable.netherlands,
                    R.drawable.nigeria,R.drawable.northkorea,R.drawable.norway,R.drawable.peru,R.drawable.philippines,R.drawable.poland,
                    R.drawable.portugal,R.drawable.quatar,R.drawable.ran,R.drawable.raq,R.drawable.russia,R.drawable.saudiarabia,
                    R.drawable.scotland,R.drawable.southafrica,R.drawable.sudan,R.drawable.sweden,R.drawable.switzerland,R.drawable.syria,
                    R.drawable.thailand,R.drawable.turkey,R.drawable.ukraine,R.drawable.unitedarabemirates,R.drawable.unitedkingdome,
                    R.drawable.usa,R.drawable.venezuela,R.drawable.vetnam};
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.flags);
        list = (ListView)findViewById(R.id.list1);
        CustomAdapter cust = new CustomAdapter(this,countryList,flags);
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
                Intent intent = new Intent(getBaseContext(), ImagePop2.class);
                intent.putExtra("Img",flags[position]);
                startActivity(intent);
            }
        });
    }
}

