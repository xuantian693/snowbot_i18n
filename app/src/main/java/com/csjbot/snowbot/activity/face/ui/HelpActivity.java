package com.csjbot.snowbot.activity.face.ui;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.csjbot.snowbot.R;
import com.csjbot.snowbot.activity.face.base.BaseActivity;


public class HelpActivity extends BaseActivity {

    private TextView page_title;
    private TextView page_right;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_help);
        page_title = (TextView) findViewById(R.id.page_title);
        page_title.setText("使用说明");
        page_right = (TextView) findViewById(R.id.page_right);
        page_right.setVisibility(View.GONE);
    }

    @Override
    public void initView() {

    }

    public void topClick(View v) {
        onBackPressed();
    }
}
