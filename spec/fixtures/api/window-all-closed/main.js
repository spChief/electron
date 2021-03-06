const { app, BrowserWindow } = require('electron')
// Suppress deprecation logs
app.allowRendererProcessReuse = true

let handled = false

if (app.commandLine.hasSwitch('handle-event')) {
  app.on('window-all-closed', () => {
    handled = true
    app.quit()
  })
}

app.on('quit', () => {
  process.stdout.write(JSON.stringify(handled))
  process.stdout.end()
})

app.on('ready', () => {
  const win = new BrowserWindow()
  win.close()
})
