namespace assignment10
{
    public partial class Form1 : Form
    {
        private const int BASICPRICE = 12;
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int price = BASICPRICE;
            int age = int.Parse(textBox1.Text);
            if(age < 5 || age > 55)
            {
                price = 0;
            }
            if (age >= 5 &&  age <= 12) 
            {
                price /= 2;
            }
            if(age >= 55)
            {
                price = BASICPRICE;
            }

            label3.Text = "€ " + price.ToString("0.00");
        }
    }
}