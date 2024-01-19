import pygame

class MusicPlayer:
    def __init__(self):
        pygame.init()
        pygame.mixer.init()
        self.is_playing = False

    def set_song(self, song_name):
        pygame.mixer.music.load(song_name)

    def play(self):
        if not self.is_playing:
            pygame.mixer.music.play()
            self.is_playing = True

    def pause(self):
        if self.is_playing:
            pygame.mixer.music.pause()
            self.is_playing = False

    def stop(self):
        if self.is_playing:
            pygame.mixer.music.stop()
            self.is_playing = False

    def resume(self):
        if not self.is_playing:
            pygame.mixer.music.unpause()
            self.is_playing = True

    def get_status(self):
        return self.is_playing

    def quit(self):
        pygame.mixer.music.stop()
        pygame.mixer.quit()
        pygame.quit()

player = MusicPlayer()
player.set_song('song.mp3')
player.play()

while True:
    command = input("输入命令 (play/pause/stop/resume/quit): ")

    if command == "play":
        player.play()
    elif command == "pause":
        player.pause()
    elif command == "stop":
        player.stop()
    elif command == "resume":
        player.resume()
    elif command == "quit":
        player.quit()
        break
    else:
        print("无效的命令。")