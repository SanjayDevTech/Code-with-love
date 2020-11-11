package com.example.timernotification;

import android.annotation.TargetApi;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.ContextWrapper;
import android.content.Intent;
import android.graphics.Color;
import android.os.Build;

import androidx.core.app.NotificationCompat;

public class NotificationHelper extends ContextWrapper{





    private static final String TAG = "NotificationHelper";

    public static final String channelID = "channelID";
    public static final String channelName = "Medicines";
    //public static final String channelID2="channelID2";
    //public static final String channelName2="Birthday";

    //private MediaSessionCompat mediaSessionCompat;

    private NotificationManager mManager;
    public NotificationHelper(Context base) {
        super(base);

        //channelIDs.add(channelID);
        //channelNames.add(channelName);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            createChannels();
        }
    }
    @TargetApi(Build.VERSION_CODES.O)
    private void createChannels() {
        //for (int i=0; i<channelIDs.size(); i++) {
        NotificationChannel  channel= new NotificationChannel(channelID, channelName, NotificationManager.IMPORTANCE_HIGH);
        getManager().createNotificationChannel(channel);

        //NotificationChannel  channel2= new NotificationChannel(channelID2, channelName2, NotificationManager.IMPORTANCE_HIGH);
        //getManager().createNotificationChannel(channel2);

        //}






    }
    public NotificationManager getManager() {
        if (mManager == null) {
            mManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
        }
        return mManager;
    }
    public NotificationCompat.Builder getChannelNotification() {
        Intent activityIntent=new Intent(this, MainActivity.class);
        activityIntent.putExtra("NotificationFragment", "MedicinesViewFragment");
        PendingIntent contentIntent=PendingIntent.getActivity(this, 0, activityIntent, 0);


        return new NotificationCompat. Builder(getApplicationContext(), channelID)
                .setContentTitle("NOTIFICATION TITLE")
                .setContentText("Notification message.")
                .setColor(Color.GREEN)
                .setContentIntent(contentIntent)
                .setAutoCancel(true)
                .setSmallIcon(R.mipmap.ic_launcher_round);

    }


}

