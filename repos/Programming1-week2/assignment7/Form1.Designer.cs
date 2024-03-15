namespace assignment7
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            label7 = new Label();
            label8 = new Label();
            label9 = new Label();
            textBox1 = new TextBox();
            textBox2 = new TextBox();
            textBox3 = new TextBox();
            button1 = new Button();
            button2 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(85, 75);
            label1.Name = "label1";
            label1.Size = new Size(78, 25);
            label1.TabIndex = 0;
            label1.Text = "Start km";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(85, 139);
            label2.Name = "label2";
            label2.Size = new Size(72, 25);
            label2.TabIndex = 1;
            label2.Text = "End km";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(85, 201);
            label3.Name = "label3";
            label3.Size = new Size(91, 25);
            label3.TabIndex = 2;
            label3.Text = "Price / km";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(85, 301);
            label4.Name = "label4";
            label4.Size = new Size(118, 25);
            label4.TabIndex = 3;
            label4.Text = "Price excl VAT";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(276, 301);
            label5.Name = "label5";
            label5.Size = new Size(42, 25);
            label5.TabIndex = 4;
            label5.Text = "VAT";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(503, 301);
            label6.Name = "label6";
            label6.Size = new Size(115, 25);
            label6.TabIndex = 5;
            label6.Text = "Price incl VAT";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(85, 360);
            label7.Name = "label7";
            label7.Size = new Size(22, 25);
            label7.TabIndex = 6;
            label7.Text = "0";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(276, 360);
            label8.Name = "label8";
            label8.Size = new Size(22, 25);
            label8.TabIndex = 7;
            label8.Text = "0";
            label8.Click += label8_Click;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(503, 360);
            label9.Name = "label9";
            label9.Size = new Size(22, 25);
            label9.TabIndex = 8;
            label9.Text = "0";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(250, 69);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(150, 31);
            textBox1.TabIndex = 9;
            // 
            // textBox2
            // 
            textBox2.Location = new Point(250, 133);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(150, 31);
            textBox2.TabIndex = 10;
            // 
            // textBox3
            // 
            textBox3.Location = new Point(250, 195);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(150, 31);
            textBox3.TabIndex = 11;
            // 
            // button1
            // 
            button1.Location = new Point(528, 75);
            button1.Name = "button1";
            button1.Size = new Size(112, 34);
            button1.TabIndex = 12;
            button1.Text = "Erase";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.Location = new Point(528, 192);
            button2.Name = "button2";
            button2.Size = new Size(112, 34);
            button2.TabIndex = 13;
            button2.Text = "Calculate";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(733, 450);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(textBox3);
            Controls.Add(textBox2);
            Controls.Add(textBox1);
            Controls.Add(label9);
            Controls.Add(label8);
            Controls.Add(label7);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        private Label label7;
        private Label label8;
        private Label label9;
        private TextBox textBox1;
        private TextBox textBox2;
        private TextBox textBox3;
        private Button button1;
        private Button button2;
    }
}