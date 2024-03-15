namespace assignment5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string input1 = textBox1.Text;
            input1 = input1.Trim();
            float num1 = float.Parse(input1);

            string input2 = textBox2.Text;
            input2 = input2.Trim();
            float num2 = float.Parse(input2);

            string input3 = textBox3.Text;
            input3 = input3.Trim();
            float num3 = float.Parse(input3);

            float average = (num1 + num2 + num3) / 3;
            label5.Text = average.ToString();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}