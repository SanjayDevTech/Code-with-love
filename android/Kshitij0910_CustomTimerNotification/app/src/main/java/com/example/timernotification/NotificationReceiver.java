package com.example.timernotification;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.util.Log;

import androidx.core.app.NotificationCompat;

import java.util.ArrayList;

import static android.content.Context.MODE_PRIVATE;

public class NotificationReceiver extends BroadcastReceiver {


    ArrayList<Integer> ids=new ArrayList<>();



    @Override
    public void onReceive(Context context, Intent intent) {
        NotificationHelper notificationHelper=new NotificationHelper(context);
        NotificationCompat.Builder nb=notificationHelper.getChannelNotification();
        SharedPreferences keyPrefs=context.getSharedPreferences("KEY", MODE_PRIVATE);
        int id=keyPrefs.getInt("Channel", 0);
        ids.add(id);
        for (int i=0; i<ids.size(); i++){
            Log.d("NotificationReceiver", "onReceive: "+ids.get(i));
            notificationHelper.getManager().notify(ids.get(i), nb.build());
        }


        }






}





