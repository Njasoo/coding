import pygame

class Square:
  def __init__(self, js_game):
    self.screen = js_game.screen
    self.screen_rect = self.screen.get_rect()
    self.settings = js_game.settings
    self.color = self.settings.square_color
    self.rect = pygame.Rect(0, 0, self.settings.square_width, self.settings.square_height)
    self.rect.midbottom = self.screen_rect.midbottom

  def draw(self):
    pygame.draw.rect(self.screen, self.color, self.rect)