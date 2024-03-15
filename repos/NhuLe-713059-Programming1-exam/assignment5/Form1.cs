using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.Diagnostics;

namespace assignment5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int age = int.Parse(textBox1.Text);
            bool isButton1 = radioButton1.Checked;
            bool isButton2 = radioButton2.Checked;
            double price = 0;

            if (isButton1)
            {
                price = 12.65;
            }
            else if (isButton2)
            {
                price = 12.00;
            }
            else
            {
                price = 11.00;
            }

            if (age > 65)
            {
                price *= 0.8;
            }
            label4.Text = price.ToString("0.00");
        }
    }
}

