package com.example.timernotification;

import android.app.AlarmManager;
import android.app.AlertDialog;
import android.app.PendingIntent;
import android.app.TimePickerDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.text.InputType;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Calendar;

public class AlarmActivity extends AppCompatActivity /*implements TimePickerDialog.OnTimeSetListener*/{

    ArrayList<Integer> ids=new ArrayList<>();
    ArrayList<PendingIntent> intentArray = new ArrayList<>();
    FloatingActionButton notification;
    RelativeLayout timell;
    TextView mTimeText,mRepeatText,  mRepeatNoText, mRepeatTypeText;

    private String mTime;
    private String mRepeatNo;
    private String mRepeatType;

    private long mRepeatTime;

    // Values for orientation change
    private static final String KEY_TIME = "time_key";
    private static final String KEY_REPEAT = "repeat_key";
    private static final String KEY_REPEAT_NO = "repeat_no_key";
    private static final String KEY_REPEAT_TYPE = "repeat_type_key";


    // Constant values in milliseconds
    private static final long milMinute = 60000L;
    private static final long milHour = 3600000L;
    private static final long milDay = 86400000L;
    private static final long milWeek = 604800000L;
    private static final long milMonth = 2592000000L;

    Calendar c = Calendar.getInstance();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_alarm);

        //Intent activityIntent=getIntent();
        //String selectedKey=activityIntent.getStringExtra("KEY");
        //final SharedPreferences itemPrefs=getSharedPreferences("Item", MODE_PRIVATE);


        notification=findViewById(R.id.notification_);
        mTimeText=findViewById(R.id.set_time);
        mRepeatText=findViewById(R.id.set_repeat);
        mRepeatNoText = findViewById(R.id.set_repeat_no);
        mRepeatTypeText =  findViewById(R.id.set_repeat_type);
        timell=findViewById(R.id.time);

        Calendar now=Calendar.getInstance();
        final int hour=now.get(Calendar.HOUR_OF_DAY);
        final int minute=now.get(Calendar.MINUTE);

        // Initialize default values
        mRepeatNo = Integer.toString(1);
        mRepeatType = "Hour";
        mTime=DateFormat.getTimeInstance(DateFormat.SHORT).format(now.getTime());

        /*int repeatNo=itemPrefs.getInt(KEY_REPEAT_NO, 1);
        String repeatType=itemPrefs.getString(KEY_REPEAT_TYPE, "Hour");
        String time=itemPrefs.getString(KEY_TIME, mTime);
        String repeatText=itemPrefs.getString("repeat_text", "Every " + "1" + " " + "Hour" + "(s)");*/

        mTimeText.setText(mTime);
        mRepeatNoText.setText(mRepeatNo);
        mRepeatTypeText.setText(mRepeatType);
        mRepeatText.setText(("Every " + mRepeatNo + " " + mRepeatType + "(s)"));

        if (savedInstanceState != null) {


            String savedTime = savedInstanceState.getString(KEY_TIME);
            mTimeText.setText(savedTime);
            mTime = savedTime;

            String saveRepeat = savedInstanceState.getString(KEY_REPEAT);
            mRepeatText.setText(saveRepeat);

            String savedRepeatNo = savedInstanceState.getString(KEY_REPEAT_NO);
            mRepeatNoText.setText(savedRepeatNo);
            mRepeatNo = savedRepeatNo;

            String savedRepeatType = savedInstanceState.getString(KEY_REPEAT_TYPE);
            mRepeatTypeText.setText(savedRepeatType);
            mRepeatType = savedRepeatType;


        }

        timell.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                TimePickerDialog timePickerDialog=new TimePickerDialog(AlarmActivity.this, new TimePickerDialog.OnTimeSetListener() {
                    @Override
                    public void onTimeSet(TimePicker view, int hourOfDay, int minute) {

                        c.set(Calendar.HOUR_OF_DAY, hourOfDay);
                        c.set(Calendar.MINUTE, minute);
                        c.set(Calendar.SECOND, 0);

                        mTime = DateFormat.getTimeInstance(DateFormat.SHORT).format(c.getTime());
                        mTimeText.setText(mTime);






                    }
                }, hour, minute, false);
                timePickerDialog.show();

            }
        });


        notification.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(AlarmActivity.this, "REMINDER SET FOR: " + DateFormat.getTimeInstance(DateFormat.SHORT).format(c.getTime()) + " every "+ mRepeatNo + " " + mRepeatType + "(s)", Toast.LENGTH_SHORT).show();

                //SharedPreferences keyPrefs=getSharedPreferences("KEY", MODE_PRIVATE);
                //int id=keyPrefs.getInt("Channel", 0);
                //ids.add(id);
                //for (int j=0; j<ids.size(); j++) {

                    if (mRepeatType.equals("Minute")) {
                        mRepeatTime = Integer.parseInt(mRepeatNo) * milMinute;
                    } else if (mRepeatType.equals("Hour")) {
                        mRepeatTime = Integer.parseInt(mRepeatNo) * milHour;
                    } else if (mRepeatType.equals("Day")) {
                        mRepeatTime = Integer.parseInt(mRepeatNo) * milDay;
                    } else if (mRepeatType.equals("Week")) {
                        mRepeatTime = Integer.parseInt(mRepeatNo) * milWeek;
                    } else if (mRepeatType.equals("Month")) {
                        mRepeatTime = Integer.parseInt(mRepeatNo) * milMonth;
                    }

                    startAlarm(c, mRepeatTime);
                //}

            }
        });
    }

    private void startAlarm(Calendar c, long repeatTime) {
        AlarmManager alarmManager = (AlarmManager)getSystemService(Context.ALARM_SERVICE);

        SharedPreferences keyPrefs=getSharedPreferences("KEY", MODE_PRIVATE);
        int id=keyPrefs.getInt("Channel", 0);
        ids.add(id);

        Log.d("AlarmActivity", "startAlarm: "+ids.size());
        for (int i=0; i<ids.size(); i++) {
            Intent intent = new Intent(this, NotificationReceiver.class);
            PendingIntent pendingIntent = PendingIntent.getBroadcast(this, ids.get(i), intent, PendingIntent.FLAG_UPDATE_CURRENT);
            if (c.before(Calendar.getInstance())) {
                c.add(Calendar.DATE, 1);
            }
            alarmManager.setRepeating(AlarmManager.RTC_WAKEUP, c.getTimeInMillis(), repeatTime, pendingIntent);

            intentArray.add(pendingIntent);
        }
    }

    @Override
    protected void onSaveInstanceState (Bundle outState) {
        super.onSaveInstanceState(outState);

        outState.putCharSequence(KEY_TIME, mTimeText.getText());
        outState.putCharSequence(KEY_REPEAT, mRepeatText.getText());
        outState.putCharSequence(KEY_REPEAT_NO, mRepeatNoText.getText());
        outState.putCharSequence(KEY_REPEAT_TYPE, mRepeatTypeText.getText());

    }


    // On clicking repeat type button
    public void selectRepeatType(View v){
        final String[] items = new String[5];

        items[0] = "Minute";
        items[1] = "Hour";
        items[2] = "Day";
        items[3] = "Week";
        items[4] = "Month";

        // Create List Dialog
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Select Type");
        builder.setItems(items, new DialogInterface.OnClickListener() {

            public void onClick(DialogInterface dialog, int item) {

                mRepeatType = items[item];
                mRepeatTypeText.setText(mRepeatType);
                mRepeatText.setText("Every " + mRepeatNo + " " + mRepeatType + "(s)");

            }
        });
        AlertDialog alert = builder.create();
        alert.show();
    }

    // On clicking repeat interval button
    public void setRepeatNo(View v){
        AlertDialog.Builder alert = new AlertDialog.Builder(this);
        alert.setTitle("Enter Number");

        // Create EditText box to input repeat number
        final EditText input = new EditText(this);
        input.setInputType(InputType.TYPE_CLASS_NUMBER);
        alert.setView(input);
        alert.setPositiveButton("Ok",
                new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int whichButton) {

                        if (input.getText().toString().length() == 0) {
                            mRepeatNo = Integer.toString(1);
                            mRepeatNoText.setText(mRepeatNo);
                            mRepeatText.setText("Every " + mRepeatNo + " " + mRepeatType + "(s)");
                        }
                        else {
                            mRepeatNo = input.getText().toString().trim();
                            mRepeatNoText.setText(mRepeatNo);
                            mRepeatText.setText("Every " + mRepeatNo + " " + mRepeatType + "(s)");
                        }
                    }
                });
        alert.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int whichButton) {
                // do nothing
            }
        });
        alert.show();
    }
}



