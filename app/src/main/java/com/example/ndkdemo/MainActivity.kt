package com.example.ndkdemo

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import com.example.ndkdemo.databinding.ActivityMainBinding
import com.example.ndkdemo.test1.TestActivity1
import com.example.ndkdemo.test2.TestActivity2
import com.example.ndkdemo.test3.TestActivity3
import com.example.ndkdemo.test4.TestActivity4

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    companion object {
        // Used to load the 'ndkdemo' library on application startup.
        init {
            System.loadLibrary("ndkdemo")
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
    }

    /**
     * 基础使用
     */
    fun onTest1(v: View) {
        startActivity(Intent(this, TestActivity1::class.java))
    }

    /**
     * Java调用C
     */
    fun onTest2(v: View) {
        startActivity(Intent(this, TestActivity2::class.java))
    }

    /**
     * C调用Java
     */
    fun onTest3(v: View) {
        startActivity(Intent(this, TestActivity3::class.java))
    }

    /**
     * JNI的常用API
     */
    fun onTest4(v: View) {
        startActivity(Intent(this, TestActivity4::class.java))
    }

}