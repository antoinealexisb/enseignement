//EXO1 .1 
function codeCesar(str, n) {
  'use strict';
  var r = '';
  var i;
  for (i = 0; i < str.length; i += 1) {
    r += String.fromCharCode(((str.charCodeAt(i) + n) - 'A'.charCodeAt(0)) % 26 + 'A'.charCodeAt(0));
  }
  return r;
}

//.2
function decodecesar(str, n) {
  'use strict';
  var r = '';
  n %= 26;
  var i;
  var res;
  for (i = 0; i < str.length; i += 1) {
    if (str.charCodeAt(i) - n - 'A'.charCodeAt(0) >= 0) {
      res = ((str.charCodeAt(i) - n) - 'A'.charCodeAt(0)) + 'A'.charCodeAt(0);
    } else {
      res = (str.charCodeAt(i) - n) - 'A'.charCodeAt(0) + 26 + 'A'.charCodeAt(0);
    }
    r += String.fromCharCode(res);
  }
  return r;
}

//.3
function codeCesar2(str, n) {
  'use strict';
  var r = '';
  var i;
  for (i = 0; i < str.length; i += 1) {
    if (str[i] !== ' ') {
      r += String.fromCharCode(((str.charCodeAt(i) + n) - 'A'.charCodeAt(0)) % 26 + 'A'.charCodeAt(0));
    } else {
      r += str[i];
    }
  }
  return r;
}

function decodecesar2(str, n) {
  'use strict';
  var r = '';
  n %= 26;
  var i;
  var res;
  for (i = 0; i < str.length; i += 1) {
    if (str[i] !== ' ') {
      if (str.charCodeAt(i) - n - 'A'.charCodeAt(0) >= 0) {
        res = ((str.charCodeAt(i) - n) - 'A'.charCodeAt(0)) + 'A'.charCodeAt(0);
      } else {
        res = (str.charCodeAt(i) - n) - 'A'.charCodeAt(0) + 26 + 'A'.charCodeAt(0);
      }
      r += String.fromCharCode(res);
    } else {
      r += str[i];
    }
  }
  return r;
}


//.4
function estSeparateur(sep, c) {
  'use strict';
  var i;
  for (i = 0; i < sep.length; i += 1) {
    if (sep[i] === c) {
      return true;
    }
  }
  return false;
}


function codeCesar3(str, n, sep) {
  'use strict';
  var r = '';
  var i;
  for (i = 0; i < str.length; i += 1) {
    if (!estSeparateur(sep, str[i])) {
      r += String.fromCharCode(((str.charCodeAt(i) + n) - 'A'.charCodeAt(0)) % 26 + 'A'.charCodeAt(0));
    } else {
      r += str[i];
    }
  }
  return r;
}

function decodecesar3(str, n, sep) {
  'use strict';
  var r = '';
  n %= 26;
  var i;
  var res;
  for (i = 0; i < str.length; i += 1) {
    if (!estSeparateur(sep, str[i])) {
      if (str.charCodeAt(i) - n - 'A'.charCodeAt(0) >= 0) {
        res = ((str.charCodeAt(i) - n) - 'A'.charCodeAt(0)) + 'A'.charCodeAt(0);
      } else {
        res = (str.charCodeAt(i) - n) - 'A'.charCodeAt(0) + 26 + 'A'.charCodeAt(0);
      }
      r += String.fromCharCode(res);
    } else {
      r += str[i];
    }
  }
  return r;
}

//EXO2
function codeSubstitution(msg, key) {
  'use strict';
  var r = '';
  var i;
  for (i = 0; i < msg.length; i += 1) {
    if (msg[i] !== ' ') {
      r += key[msg.charCodeAt(i) - 'A'.charCodeAt(0)];
    } else {
      r += msg[i];
    }
  }
  return r;
}

function decodeSubstitution(msg, key) {
  'use strict';
  var r = '';
  var i;
  for (i = 0; i < msg.length; i += 1) {
    if (msg[i] !== ' ') {
      r += String.fromCharCode(key.indexOf(msg[i]) + 'A'.charCodeAt(0));
    } else {
      r += msg[i];
    }
  }
  return r;
}//EXO1 .1 
function codeCesar(str, n) {
  'use strict';
  var r = '';
  var i;
  for (i = 0; i < str.length; i += 1) {
    r += String.fromCharCode(((str.charCodeAt(i) + n) - 'A'.charCodeAt(0)) % 26 + 'A'.charCodeAt(0));
  }
  return r;
}

//.2
function decodecesar(str, n) {
  'use strict';
  var r = '';
  n %= 26;
  var i;
  var res;
  for (i = 0; i < str.length; i += 1) {
    if (str.charCodeAt(i) - n - 'A'.charCodeAt(0) >= 0) {
      res = ((str.charCodeAt(i) - n) - 'A'.charCodeAt(0)) + 'A'.charCodeAt(0);
    } else {
      res = (str.charCodeAt(i) - n) - 'A'.charCodeAt(0) + 26 + 'A'.charCodeAt(0);
    }
    r += String.fromCharCode(res);
  }
  return r;
}

//.3
function codeCesar2(str, n) {
  'use strict';
  var r = '';
  var i;
  for (i = 0; i < str.length; i += 1) {
    if (str[i] !== ' ') {
      r += String.fromCharCode(((str.charCodeAt(i) + n) - 'A'.charCodeAt(0)) % 26 + 'A'.charCodeAt(0));
    } else {
      r += str[i];
    }
  }
  return r;
}

function decodecesar2(str, n) {
  'use strict';
  var r = '';
  n %= 26;
  var i;
  var res;
  for (i = 0; i < str.length; i += 1) {
    if (str[i] !== ' ') {
      if (str.charCodeAt(i) - n - 'A'.charCodeAt(0) >= 0) {
        res = ((str.charCodeAt(i) - n) - 'A'.charCodeAt(0)) + 'A'.charCodeAt(0);
      } else {
        res = (str.charCodeAt(i) - n) - 'A'.charCodeAt(0) + 26 + 'A'.charCodeAt(0);
      }
      r += String.fromCharCode(res);
    } else {
      r += str[i];
    }
  }
  return r;
}


//.4
function estSeparateur(sep, c) {
  'use strict';
  var i;
  for (i = 0; i < sep.length; i += 1) {
    if (sep[i] === c) {
      return true;
    }
  }
  return false;
}


function codeCesar3(str, n, sep) {
  'use strict';
  var r = '';
  var i;
  for (i = 0; i < str.length; i += 1) {
    if (!estSeparateur(sep, str[i])) {
      r += String.fromCharCode(((str.charCodeAt(i) + n) - 'A'.charCodeAt(0)) % 26 + 'A'.charCodeAt(0));
    } else {
      r += str[i];
    }
  }
  return r;
}

function decodecesar3(str, n, sep) {
  'use strict';
  var r = '';
  n %= 26;
  var i;
  var res;
  for (i = 0; i < str.length; i += 1) {
    if (!estSeparateur(sep, str[i])) {
      if (str.charCodeAt(i) - n - 'A'.charCodeAt(0) >= 0) {
        res = ((str.charCodeAt(i) - n) - 'A'.charCodeAt(0)) + 'A'.charCodeAt(0);
      } else {
        res = (str.charCodeAt(i) - n) - 'A'.charCodeAt(0) + 26 + 'A'.charCodeAt(0);
      }
      r += String.fromCharCode(res);
    } else {
      r += str[i];
    }
  }
  return r;
}

//EXO2
function codeSubstitution(msg, key) {
  'use strict';
  var r = '';
  var i;
  for (i = 0; i < msg.length; i += 1) {
    if (msg[i] !== ' ') {
      r += key[msg.charCodeAt(i) - 'A'.charCodeAt(0)];
    } else {
      r += msg[i];
    }
  }
  return r;
}

function decodeSubstitution(msg, key) {
  'use strict';
  var r = '';
  var i;
  for (i = 0; i < msg.length; i += 1) {
    if (msg[i] !== ' ') {
      r += String.fromCharCode(key.indexOf(msg[i]) + 'A'.charCodeAt(0));
    } else {
      r += msg[i];
    }
  }
  return r;
}
