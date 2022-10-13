const PORT=process.env.PORT||3000
const express=require("express")
const bodyParser=require("body-parser")
const mongoose=require("mongoose")
const bcrypt=require("bcrypt")
const app =express();
app.use(express.urlencoded({extended:true}))
mongoose.connect("mongodb://localhost:27017/userDB");
const userSchema=mongoose.Schema({
    name:String,
    password:String
})

const User=mongoose.model("user",userSchema)

app.get("/",function(req,res){
    res.send("Welcome to User storage API")
})

app.post("/:username",function(req,res){
    bcrypt.hash(req.body.password,10,function(err,hash){
        if(err){
            console.log(err)
        }else{
            const newuser=new User({
                name:req.params.username,
                password:hash
            })
            newuser.save();
        }
        
    })
})

app.listen(PORT,function(){
    console.log(`Server is Listening on Port ${PORT}` )
})