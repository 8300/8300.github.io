    function addToHomeScreen() {
      if (window.navigator && window.navigator["standalone"]) {
        // 当页面在 Web App 模式下打开时，直接返回
        //return;
      }
      var manifest = document.querySelector('link[rel="manifest"]');
      if (manifest) {
        // 弹出安装提示
        window.prompt("To install this web app, tap 'Share' icon below and select 'Add to Home Screen'.");
      }
    }
