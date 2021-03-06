## Strengths
The two biggest strengths of this project include the use of a confusing XOR key, and the struct that houses all modifiable member variables. Not only this, but the way we have incorporated a linked list into the traversal of these member variables makes our encryption process even more confusing. This is not normally a good thing, but in the context of this project, it's exactly what we need.<br>
The XOR'ing scheme we have implemented also keeps the complexity of our project at a minimum. The same key can be used for both encryption and decryption, which means that we have to do very little work in terms of displaying information to the user. 
## Weaknesses
The XOR key we have used presents a double-edged sword situation. It may be very versatile and convenient, but if the key is discovered, it makes it very easy for the attacker to decrypt the user's information. Strings are especially easy to spot in disassemblers like IDA pro, and so if the attacker discovers that the "fake pointer" is actually the key, then the security of the outfile is reduced to nothing.<br>
Another weakness is in the way we must encrypt the member variables of our struct after the user has entered information. We must, somewhat clumsily, traverse to a new variable each time, and encrypt it in it's own loop. We use a temporary char buffer in an attempt to draw attention away from the fact that ten separate looping procedures are used to encrypt user data. Encryption is slightly different, as we read character by character to ensure that everything is decrypted properly.
## Hash Weaknesses 
Unfortunately, at this time, Hash checking is not functioning correctly. Comparing different files with the same encrypted data results in different hash values for the two files.  
## Windows Difficulties 
It is recommended that these two programs be run in a Linux environment. The program fileRead.c and its imported c source file, hashCheck.c, use libraries that are not readily availiable in a Windows environment without additional installations. To quote Dr. Buckner, "C programming on Windows just sucks."
## Future Changes
Some of our future changes would include the following:<br>
Less obvious looping and file writing sequence, we should attempt to jump around more and follow a less logical encryption process. Something that is almost never said for anything else.<br>
Perhaps incorporating BASE_64 encryption. While XOR'ing is easy and straightforward, we may want to use a more complex encryption sequence/key for more sensitive information.<br>
Less primitive file reading. Currently, we use a do-while loop to read in encrypted character information, for every character in the file. In the future, we should consider reading the entire file to a buffer, and decrypting that buffer.<br>
Debugging the hash check functionality to get it to function in the intended manner.
