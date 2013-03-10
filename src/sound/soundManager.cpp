#include <sound/soundManager.h>

SoundManager::SoundManager(){
    soundIndex = -1;
}

SoundManager::~SoundManager(){

}

void SoundManager::open(char* path){
   ALLEGRO_SAMPLE *sample=NULL;
   sample = al_load_sample(path);
 
   if (!sample){
  cout<<"[Sound Manager] Could not load audio file: "<<path<<endl;
   }else{
       ALLEGRO_SAMPLE_INSTANCE* i = al_create_sample_instance(sample);
        al_attach_sample_instance_to_mixer(i, al_get_default_mixer());
        al_set_sample_instance_playing(i, true);
        //auto pos = al_get_sample_instance_position(i);
       sounds.push_back(sample);
   }
   soundIndex = 0;

}

void SoundManager::play(){
    if(sounds.size()!=0){
        
        al_play_sample(sounds[soundIndex], 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
        soundIndex++;
        if(soundIndex>=sounds.size()){
            soundIndex=0;
        }
    
    }
    
}

void SoundManager::stop(){
    
}


bool SoundManager::playing(){
    /*
ALLEGRO_SAMPLE* s = al_load_sample("Sound/sample1.ogg");
ALLEGRO_SAMPLE_INSTANCE* i = al_create_sample_instance(s);
al_attach_sample_instance_to_mixer(i, al_get_default_mixer());
al_set_sample_instance_playing(i, true);
auto pos = al_get_sample_instance_position(i);
    */
}
