// discordbotgen.cpp : This file contains the 'main' function.
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

string check() {
    int input, opt, opt2, opt3;
    int kill = 0;
    string temp, temp2, temp3, temp4, prefix, token, customMessage, commandName;
    string toRet = "require(\"child_process\").execSync(\"npm i discord.js\");const Discord = require('discord.js');\
const client = new Discord.Client();client.on(\"ready\",async()=>{console.log(\"ready\")});";
    string commands = "client.on(\"message\", async(message)=>{let messageArray=message.content.split(\" \");let [cmd, args]=[messageArray[0], messageArray.slice(1)];";

    cout << "Prefix: ";
    cin >> prefix;
    replace(prefix, "\"", "\\\"");

    cout << "Token: ";
    cin >> token;

    toRet += "client.login(\"" + token + "\");";

    while (kill == 0) {
        cout << "options:\n1: add command\n2: generate and finish\n\noption: ";
        cin >> temp;

        input = stoi(temp);


        switch (input)
        {
        case 1:
            cout << "options:\n1: custom message\n2: fun\n3: util\n\noption:";
            cin >> temp2;

            opt = stoi(temp2);

            // commands
            switch (opt)
            {
            case 1:
                cout << "command name (singular word): ";cin >> commandName;
                cout << "custom message: ";
                cin.ignore();
                getline(cin, customMessage);
                commands += "if(cmd==\"" + prefix + commandName + "\") {message.channel.send(\"" + customMessage + "\")};";
                break;

            case 2:
                cout << "options:\n1: 8ball\n2: percent\n\noption: ";
                cin >> temp3;

                opt2 = stoi(temp3);
                switch (opt2)
                {
                case 1:
                    commands += "if(cmd==\"" + prefix + "8ball" + "\") {message.channel.send([\"yes\",\"no\",\"maybe\"][Math.floor(Math.random()*3)])};";
                    break;

                case 2:
                    commands += "if(cmd==\"" + prefix + "percent" + "\") {message.channel.send(`${Math.floor(Math.random() * 100)}%`)};";
                    break;
                }
                break;

            case 3:
                cout << "options:\n1: invite\n2: support server (server)\n";
                cin >> temp4;
                opt3 = stoi(temp4);
                switch (opt3)
                {
                case 1:
                    commands += "if(cmd==\"" + prefix + "invite" + "\") {message.channel.send(await message.client.generateInvite())};";
                    break;

                case 2:
                    string invite;
                    cout << "Invite link: ";
                    cin >> invite;
                    commands += "if(cmd==\"" + prefix + "server" + "\") {message.channel.send('" + invite + "')};";
                    break;
                }
                break;
            /*
            case 4:
                commands += "if(cmd===\"" + prefix + "ban" + "\") {if(!args[0] || args[1]) return; let [user, author, reason] = [message.mentions.members.first(), message.author, args.join(\" \").slice(22)]; if (user.permissions.has(\"MANAGE_MESSAGES\")) return message.reply(\"This user is unable to be banned!\");if (!message.member.hasPermission(\"BAN_MEMBERS\")) return message.reply(\"No permissions!\"); try {user.ban(reason)} catch(e) {message.reply(\"err\")}};";
                commands += "if(cmd===\"" + prefix + "kick" + "\") {if(!args[0] || args[1]) return; let [user, author, reason] = [message.mentions.members.first(), message.author, args.join(\" \").slice(22)]; if (user.permissions.has(\"MANAGE_MESSAGES\")) return message.reply(\"This user is unable to be kicked!\");if (!message.member.hasPermission(\"KICK_MEMBERS\")) return message.reply(\"No permissions!\"); try {user.kick(reason)} catch(e) {message.reply(\"err\")}};";
                // fix later
                // commands += "if(cmd===\"" + prefix + "purge" + "\") {if(!message.member.permissions.has(\"MANAGE_MESSAGES\"))return message.channel.send(\"no\");try{let purgeAmount=args[0];message.channel.bulkDelete(\`${purgeAmount}\`);message.channel.send(\`${purgeAmount}purged!\`);}catch(e){message.reply(\"Bot is missing permissions\")};}";
                
                break;
            */  

                // default:
                // break;
            }
            break;
            
        case 2:
            kill = 1;continue;
            break;

            // default:
            // break;
        }
    }

    return toRet + commands + "})";
}


int main() {
    string output = check(), path;

    cout << "Discord Bot Generator by sudocode1 & 1s3k3b" << endl;
    cout << "Program written in C++, Bots written in JavaScript (with discord.js)." << endl;

    cout << "\n\n=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "You need the Node.js runtime installed, with the discord.js npm package.\n=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";

    cout << "file name: ";
    cin >> path;



    ofstream file(path.c_str());
    file << output;
    file.close();

    std::cout << "Successfully output code to " << path;

    if (system(NULL)) {
        char res;
        std::cout << "\nDo you want to run the file? [Y/N] ";
        std::cin >> res;
        if (res == 'y' || res == 'Y') {
            int node_v = system("node -v");
            if (node_v != 0) std::cout << "Node.js not found.";
            else system(("node " + path).c_str());
        }
    }

    return 0;
}
