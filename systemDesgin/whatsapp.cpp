1) User chat
2) User share
3) Contact Sycn
4) User Setting-> Block/Unblock Seen/LastSeen, Story setting
5) Story
6)WhatSapp voice/video
7) whatsapp groups create

class User{
    int id;
    int firstName;
    int lastName;
    int age;
    String about;

}

enum Participant{
    ADMIN,NORMAL
}

class UserGroup{
    int id;
    HashMap<Integers,Participant> users;
    String groupName;
    String groupAbout;
    Date dateCreatedp;
    boolean isActive;
}

class WhatsApp{
    apis:
    void createUser(User user){

    }
    void loginUser()
}

enum MessageState{
    SENT,DELIVERED,READ
}

class Message{
    int id;
    int senderUserId;
    int receiverUserId;
    TimeStamp dateDelivered;
    MessageState state;
}

interface chat{
    List<Message> getMessages;
    void sendMessage();
    //WebSocket
    void getMessage();
}

class oneToOneChat implements chat{
    @override
    void sendMessage(String message,User sender)
}