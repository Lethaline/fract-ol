const Discord = require('discord.js');
const client = new Discord.Client();
const config = require('./Configs/config.json');

client.on('message', message => {
    if(message.content.toLowerCase() === 'salut') {
        message.react('😍');
    }
});

client.login(config.token);