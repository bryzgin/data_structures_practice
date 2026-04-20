class Node:
  def __init__(self, data):
    self.data = data
    self.next = None


class LinkedList:
  def __init__(self):
    self.head = None

  def append(self, data):
    new_node = Node(data)
    
    if not self.head:
      self.head = new_node
      return
    
    current = self.head
    
    while current.next:
      current = current.next
    current.next = new_node

  def prepend(self, data):
    new_node = Node(data)
    new_node.next = self.head
    self.head = new_node

  def display(self):
    current = self.head
    elements = []

    while current:
      elements.append(str(current.data))
      current = current.next
    print(' -> '.join(elements) + " -> None")

  def delete(self, key):
    current = self.head

    if current and current.data == key:
      self.head = current.next
      current = None
      return

    prev = None
    while current and current.data != key:
      prev = current
      current = current.next

    if current is None:
      return

    prev.next = current.next
    current = None
