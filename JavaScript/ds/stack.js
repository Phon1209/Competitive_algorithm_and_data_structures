const Stack = function() {
  const container = [];

  function push(newItem) {
    container.push(newItem);
  }

  function pop() {
    if(empty()) return null;
    return container.pop();
  }

  function top() {
    if(empty()) return null;
    return container[container.length - 1];
  }

  function size() {
    return container.length;
  }

  function empty() {
    return container.length == 0;
  }

  return {
    push,
    pop,
    top,
    empty,
    size,
  }
}

const test = Stack();