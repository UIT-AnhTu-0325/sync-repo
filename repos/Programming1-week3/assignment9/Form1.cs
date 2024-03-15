namespace assignment9
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool isFootball = radioButton1.Checked;
            int age = int.Parse(textBox1.Text);
            int dur = int.Parse(textBox2.Text);
            int price = 0;
            if (isFootball)
            {
                price = 175;
            }
            else
            {
                price = 225;
            }

            if (age > 40)
            {
                price -= 25;
            }

            if (dur > 10)
            {
                price -= 20;
            }

            label5.Text = "€ " + price.ToString("0.00");
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}