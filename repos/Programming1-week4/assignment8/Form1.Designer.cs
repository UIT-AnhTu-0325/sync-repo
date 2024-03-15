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
            textBox1 = new TextBox();
            button1 = new Button();
            label5 = new Label();
            label6 = new Label();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(107, 52);
            label1.Name = "label1";
            label1.Size = new Size(158, 25);
            label1.TabIndex = 0;
            label1.Text = "Enter a number (n)";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(107, 206);
            label2.Name = "label2";
            label2.Size = new Size(176, 25);
            label2.TabIndex = 1;
            label2.Text = "sum = 1 + 2 + ... + n";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(107, 283);
            label3.Name = "label3";
            label3.Size = new Size(175, 25);
            label3.TabIndex = 2;
            label3.Text = "sum = n * (n + 1) / 2";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(107, 366);
            label4.Name = "label4";
            label4.Size = new Size(262, 25);
            label4.TabIndex = 3;
            label4.Text = "The sum and formula are equal.";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(443, 46);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(150, 31);
            textBox1.TabIndex = 4;
            // 
            // button1
            // 
            button1.Font = new Font("Segoe UI", 10F, FontStyle.Regular, GraphicsUnit.Point);
            button1.Location = new Point(107, 120);
            button1.Name = "button1";
            button1.Size = new Size(486, 48);
            button1.TabIndex = 5;
            button1.Text = "Compare";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.ImageAlign = ContentAlignment.MiddleRight;
            label5.Location = new Point(443, 206);
            label5.Name = "label5";
            label5.Size = new Size(22, 25);
            label5.TabIndex = 6;
            label5.Text = "0";
            label5.TextAlign = ContentAlignment.MiddleRight;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(443, 283);
            label6.Name = "label6";
            label6.Size = new Size(22, 25);
            label6.TabIndex = 7;
            label6.Text = "0";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(button1);
            Controls.Add(textBox1);
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
        private TextBox textBox1;
        private Button button1;
        private Label label5;
        private Label label6;
    }
}