namespace assignment8
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
            label10 = new Label();
            label11 = new Label();
            button1 = new Button();
            textBox1 = new TextBox();
            textBox2 = new TextBox();
            pictureBox1 = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(97, 65);
            label1.Name = "label1";
            label1.Size = new Size(258, 25);
            label1.TabIndex = 0;
            label1.Text = "Number of T-shirts ( x € 30,00):";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(97, 118);
            label2.Name = "label2";
            label2.Size = new Size(250, 25);
            label2.TabIndex = 1;
            label2.Text = "Number of jeans ( x € 100,00):";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(97, 276);
            label3.Name = "label3";
            label3.Size = new Size(68, 25);
            label3.TabIndex = 2;
            label3.Text = "Invoice";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(97, 330);
            label4.Name = "label4";
            label4.Size = new Size(53, 25);
            label4.TabIndex = 3;
            label4.Text = "Date:";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(97, 378);
            label5.Name = "label5";
            label5.Size = new Size(53, 25);
            label5.TabIndex = 4;
            label5.Text = "Price:";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(97, 428);
            label6.Name = "label6";
            label6.Size = new Size(46, 25);
            label6.TabIndex = 5;
            label6.Text = "VAT:";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(97, 476);
            label7.Name = "label7";
            label7.Size = new Size(96, 25);
            label7.TabIndex = 6;
            label7.Text = "Total price:";
            // 
            // label8
            // 
            label8.Location = new Point(230, 330);
            label8.Name = "label8";
            label8.RightToLeft = RightToLeft.No;
            label8.Size = new Size(300, 25);
            label8.TabIndex = 7;
            label8.Text = "0";
            label8.TextAlign = ContentAlignment.MiddleRight;
            // 
            // label9
            // 
            label9.Location = new Point(230, 378);
            label9.Name = "label9";
            label9.RightToLeft = RightToLeft.No;
            label9.Size = new Size(300, 25);
            label9.TabIndex = 8;
            label9.Text = "0";
            label9.TextAlign = ContentAlignment.MiddleRight;
            // 
            // label10
            // 
            label10.Location = new Point(230, 428);
            label10.Name = "label10";
            label10.RightToLeft = RightToLeft.No;
            label10.Size = new Size(300, 25);
            label10.TabIndex = 9;
            label10.Text = "0";
            label10.TextAlign = ContentAlignment.TopRight;
            // 
            // label11
            // 
            label11.Location = new Point(230, 476);
            label11.Name = "label11";
            label11.RightToLeft = RightToLeft.No;
            label11.Size = new Size(300, 25);
            label11.TabIndex = 10;
            label11.Text = "0";
            label11.TextAlign = ContentAlignment.TopRight;
            // 
            // button1
            // 
            button1.ImageAlign = ContentAlignment.TopCenter;
            button1.Location = new Point(97, 180);
            button1.Name = "button1";
            button1.Size = new Size(433, 60);
            button1.TabIndex = 11;
            button1.Text = "Calculate";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(380, 59);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(150, 31);
            textBox1.TabIndex = 12;
            // 
            // textBox2
            // 
            textBox2.Location = new Point(380, 115);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(150, 31);
            textBox2.TabIndex = 13;
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = Color.Gainsboro;
            pictureBox1.Image = Properties.Resources.calculator;
            pictureBox1.Location = new Point(102, 186);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(48, 48);
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox1.TabIndex = 14;
            pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.Control;
            ClientSize = new Size(676, 579);
            Controls.Add(pictureBox1);
            Controls.Add(textBox2);
            Controls.Add(textBox1);
            Controls.Add(button1);
            Controls.Add(label11);
            Controls.Add(label10);
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
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
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
        private Label label10;
        private Label label11;
        private Button button1;
        private TextBox textBox1;
        private TextBox textBox2;
        private PictureBox pictureBox1;
    }
}