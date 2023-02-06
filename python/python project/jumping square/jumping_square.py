from settings import Settings
from square import Square
import pygame
import sys

class JumpingSquare:
  def __init__(self):
    self.screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
    self.settings = Settings()
    self.square = Square(self)
    
  def _check_event(self):
    for event in pygame.event.get():
      if event.type == pygame.QUIT:
        sys.exit()
      elif event.type == pygame.KEYDOWN:
        self._check_keydown_event(event)
      elif event.type == pygame.KEYUP:
        self._check_keyup_event(event)

  def _check_keydown_event(self, event):
    if event.key == pygame.K_RIGHT:
      self.square.moving_right = True:
    if event.key == pygame.

  def run_game(self):
    while True:
      self.screen.fill(self.settings.bg_color)
      self.square.draw()
      pygame.display.flip()

if __name__ == '__main__':
  js = JumpingSquare()
  js.run_game()