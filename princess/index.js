const { Builder, By, until } = require('selenium-webdriver');
const fs = require('fs'); // Import fs module to interact with the file system
const users = require('./users');

async function loginTest() {
  let driver = await new Builder().forBrowser('chrome').build();

  // We'll collect the login results here
  let results = [];

  try {
    for (let user of users) {
      console.log(`Testing login for: ${user.username}`);
      let result = { username: user.username, success: false, message: '' };

      // Navigate to the login page
      await driver.get('https://beta-building.8ten.cloud/');

      // Input username and password
      await driver.findElement(By.id('login-email')).sendKeys(user.username);
      await driver.findElement(By.id('login-password')).sendKeys(user.password);

      // Click login button
      await driver
        .findElement(
          By.xpath('/html/body/div[1]/div/div/div[1]/form/div[3]/button')
        )
        .click();

      try {
        // Wait for the dashboard or a unique element on the landing page after login
        await driver.wait(until.elementLocated(By.id('sidebar')), 6000);

        // If login is successful, mark success and add a message
        result.success = true;
        result.message = 'Login successful!';

        // Logout process
        await driver
          .findElement(
            By.xpath('/html/body/div[1]/div/div/aside/nav/ul[2]/li/p/button')
          )
          .click();

        // Wait for the login page to reload
        await driver.wait(
          until.elementLocated(By.xpath('/html/body/div[1]/div')),
          6000
        );
      } catch (e) {
        result.success = false;
        result.message = 'Login failed!';
      }

      // Add the result to the results array
      results.push(result);
    }
  } catch (error) {
    console.error('An error occurred during the test:', error);
  } finally {
    await driver.quit();

    // Write the results to result.js (overwrite if exists)
    const resultsPath = './result.js';
    const resultContent = `module.exports = ${JSON.stringify(
      results,
      null,
      2
    )};`;

    // Use fs.writeFileSync to overwrite the file or create it if it doesn't exist
    fs.writeFileSync(resultsPath, resultContent, 'utf8');

    console.log('Results saved to result.js');
  }
}

// Run the test
loginTest();
