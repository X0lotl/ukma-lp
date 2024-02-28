const session = pl.create(1000)

session.consult("/code.pl", {
  success: function () {
    session.query("test_alert.", {
      success: function (goal) {

        session.answer({
          success: function (answer) {
            session.format_answer(answer);
          },
          error: function (err) {
            console.log("Error: " + err);
          },
        }
        );
      },
    });

    session.query("test_dom_editing.", {
      success: function (goal) {

        session.answer({
          success: function (answer) {
            session.format_answer(answer);
          },
          error: function (err) {
            console.log("Error: " + err);
          },
        }
        );
      },
    });
  }
});