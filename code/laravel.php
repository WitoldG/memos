A changer pour le déploiement du site
config/app.php: 'debug' => env('APP_DEBUG', false),
Changement de langue :
https://openclassrooms.com/en/courses/3613341-decouvrez-le-framework-php-laravel/3617070-la-validation#r-3647283


----------------------
------- START --------
----------------------
composer create-project --prefer-dist laravel/laravel <project-folder-name>
in the folder: php artisan serve
connection to: http://localhost:8000


----------------------
------- ROUTES -------
----------------------
app/routes/web.php

<?php
Route::get('/', function () { /* Appel de la racine du site avec la méthode get */
    return view('welcome');
}); ?>

--- Route dépendant d'une variable
<?php
Route::get('{n}', function($n) {
	return 'Je suis la page ' . $n . ' !';
}); ?>
<!-- Paramètre optionnel avec un ?, doivent tous être à la fin -->
  Contraindre le paramètre à certaines valeurs:
  <?php
  Route::get('{n}', function($n) {
      return 'Je suis la page ' . $n . ' !';
  })->where('n', '[1-3]'); ?>

--- Route nommée
<?php
Route::get('/', ['as' => 'home', function()
{
  return 'Je suis la page d\'accueil !';
}]); ?>

--- Réponse
Permet de retourner un code en plus
<?php return response('Je suis la page ' . $n . ' !', 200); ?>


----------------------
-------- MVC ---------
----------------------

Contrôleur : gère précisément les routes, permet d'appeler des fonctions pour avoir des données avant d'envoyer une vue

Vue : Code HTML de la page utilisant les données envoyées par le contrôleur

DAO : interagit avec la BD. Si besoin d'une liste de trucs dans la BD on va faire une fonction qui retourne cette liste dans le DAO


----------------------
---- ARBORESCENCE ----
----------------------
📁laravel
	↳ 📁app → code source de la page
		↳ 📁Console → artisan commands for laravel
			↳ inspire.php -> where to declare the commands
		↳ kernel.php → where to call the commands
		↳ 📁events
			↳ events.php → used to trigger activities
		↳ 📁exceptions
			↳ handle.php → contains methods to handle exceptions
		↳ 📁Http → model, controllers
			↳ 📁Middleware → filter mechanism, communication between response and request
			↳ 📁request → requests of the application
		↳ 📁jobs → maintains the activities queued for Laravel application
		↳ 📁listeners → include methods to handle events and exceptions
		↳ 📁policies → authorization logic, can add policy classes
	↳ 📁bootstrap → application bootstrap scripts
	↳ 📁config → configuration and parameters
	↳ 📁database → various parameters for database functionnalities
		↳ 📁seeds → classes for unit testing database
		↳ 📁migrations → helps in queries for migrating the database
		↳ 📁factories → used to generate large number of data records
	↳ 📁Public → root folder helping initializingthe application
		↳ .htaccess → server configuration
		↳ index.php → required for application intialization
	↳ 📁Resources
		↳ 📁assets → LESS and SCSS
		↳ 📁lang → files for localization or intertionalization
		↳ 📁views → HTML
	↳ 📁Storage → logs,sessions...
	↳ 📁Vendor → Composer dependencies

----------------------
------- VIEWS --------
----------------------
A enregistrer dans resources/views, tjrs au format php
Appel de la vue : <?php return view('vue1') ?>
Vue paramétrée
  Récupérer requête du type http://monsite.fr/article/n:
  <?php
    Route::get('article/{n}', function($n) {
    return view('article')->with('numero', $n);
    })->where('n', '[0-9]+');
  ?>
  <!doctype html>
  <html lang="fr">
  <head>
    <meta charset="UTF-8">
    <title>Les articles</title>
  </head>
  <body><p>C'est l'article n° <?php echo $numero ?></p></body>
  </html>
  Other way to parameterize a view with array: see blade section

Utilisation de CSS : placer dans public/css, {{ HTML::style('css/style.css'); }}


-------------------
--- CONTROLLER ---
-------------------
Creation: php artisan make:controller <controller-name>
Location: app/Http/Controllers
to put them elsewhere, modify $namespace in App\Providers\RouteServiceProvider

<?php
class ControllerName extends Controller{
	public function index(){
		return view('welcome'); //to a view
		return redirect()->route('login'); //to a route
		return redirect('/add_event'); //to an url
	}
} ?>

<!-- Route à utiliser -->
<?php Route::get('/', 'ControllerName@method'); ?>

Contrôleur + variable
<?php
class ArticleController extends Controller{ /*controler*/
	public function show($n){
		return view('article')->with('numero', $n);
	}
}
Route::get('article/{n}', 'ArticleController@show')->where('n', '[0-9]+'); /*Route*/
?>

Can associate a middleware into the controller:
<?php $this->middleware('MiddlewareName'); ?>
will be launched after a middleware setup with the route

Utilisation de fonction : injection de dépendances


----------------------
----- MIDDLEWARE -----
----------------------
Execute standard operations on redirections: check if an user is logged, filter by a parameter. The controller executes more complicated operations and retrieve data from the models
Two types
↳ global middleware -> run on every http request
↳ route middleware -> specific on a route

need to be registrated on app/Http/kernel.php (array middleware for global, array routeMiddleware for route middlewares)
ex: 'Age' => \App\Http\Middleware\AgeMiddleware::class,

Creation: php artisan make:middleware <name>

Use parameters
	- Add parameter to handle function
	class RoleMiddleware {
		public function handle($request, Closure $next, $role) {
			echo "Role: ".$role;
			return $next($request);}}
	- Register normally
	'Role' => /App/Http/Middleware/RoleMiddleware::class,
	- Create the route
	Route::get('role',[
		'middleware' => 'Role:<valueOf$role>',
		'uses' => '<ControllerName>@index',
	]);

Terminable middleware
	- performs some task after the response has been sent to the browser
	- can be accomplished by creating a middleware with terminate method in the middleware (middleware can also have handle function)
	- need to be registered with global middlewares ?
	- ex: public function terminate($request, $response) {
			echo "<br>Sentence print at the end";}





----------------------
------- BLADE --------
----------------------
Activation: file.blade.php
{{ $numero }} au mieu de <?php echo $numero ?>

Permet les template
  template.blade.php:
  <!doctype html>
  <html lang="fr">
  <head>
      <meta charset="UTF-8">
      <title>@yield('titre')</title>
  </head>
  <body> @yield('contenu') </body>
  </html>

  article.blade.php:
  @extends('template') <!-- dit à quel template ça réfère -->
  @section('titre')
      Les articles
  @endsection

  @section('contenu')
      <p>C'est l'article n° {{ $numero }}</p>
  @endsection

  @if(session()->has('error'))
    Code...
  @endif

Using controller parameters:
<?php return view('stud_view',['users'=>$users]); ?>
@foreach ($users as $user)
	<tr>
		<td>{{ $user->id }}</td>
		<td>{{ $user->name }}</td>
	</tr>
@endforeach

CSS:
	in public/css/
	<link rel="stylesheet" href={{ asset('/css/style_general.css') }} />
images:
	in public/img/
	<img src={{ asset('img/photo.png') }} alt="photo">


--------------------
--- REDIRECTIONS ---
--------------------

<?php return redirect()->route('facture'); ?>


------------------
--- FORMULAIRE ---
------------------
Utilisation de la facade form qui sécurise le formulaire contre l'envoi par une autre page
Install form facade: https://stackoverflow.com/questions/28753767/laravel-5-class-form-not-found#answer-37243805
@section('contenu')
<?php
	Form::open(['url' => 'site.myForm.php']); // can specify an url
	Form::open(['route' => 'route.name']); // or a route
	Form::open(['route' => ['route.name', $user->id]]); // give params to route
	Form::open(['url' => 'foo/bar', 'files' => true]); // if form accepts files

	Form::label('nom', 'Entrez votre nom : ');
	Form::input('type', 'name', null, [options])
    Form::input('text', 'nom', null, ['class' => 'form-control', 'placeholder' => 'witold']) //to use bootstrap...
    Form::submit('Envoyer !');
	//every entries: https://laravel.com/docs/4.2/html
  Form::close(); ?>
@endsection

In the controller called, retrieve elements with
<?php
public function insert(Request $request) {
	$name = $request->input('stud_name');
?>

-------------------
------SESSION------
-------------------
Informations enregistrées tout le long de la connexion d'un utilisateur
<?php
  Session::put('clef', 'valeur');
  $valeur = Session::get('clef');
  if (Session::has('error')); //savoir si une clé est présente en session
?>

-------------------
---CONFIGURATION---
-------------------
Accession à une valeur de config :
  config/view.php: <?php
    'paths' => [
        realpath(base_path('resources/views'))], ?>
  access by: <?php Config::get('view.paths'); ?>
Modification d'une valeur :
  <?php Config::set('view.paths', [base_path().'/mes_vues']); ?>


-----------------
---- REQUEST ----
-----------------
<?php
$request -> path(); //shows method path
$request -> url(); //gives the url for accession
$request->input('username'); //retrieve the value of a form input
$request->username; //same
?>


----------------
--- RESPONSE ---
----------------
<?php
//Basic response
Route::get('/basic_response', function () {
   return 'Hello World';
});
?>


----------------
---- COOKIE ----
----------------
<?php
// Creation
cookie('name', 'value', $minutes); //duration: $minutes
cookie()->forever('name', 'value'); //duration: forever
// Attach to a response
$response->withCookie($cookie);
//Retrieving
$request -> cookie('name');
?>

----------------------
------ DATABASE ------
----------------------
<!-- CONFIGURATION -->
into ./env
DB_CONNECTION=mysql
DB_HOST=127.0.0.1
DB_PORT=8889 <!-- for MAMP -->
DB_DATABASE=homestead
DB_USERNAME=homestead
DB_PASSWORD=secret


<!-- MIGRATION: Setup the tables -->
Allows to create a dtabase schema that save all the modifications to apply them on all versions
Migration install: php artisan migrate:install
Create migration for a table: php artisan make:migration create_emails_table
↳ database/migration/..._create_emails_table
Run the migration: php artisan migrate
Rollback the run: php artisan migrate:rollback

into database/migration:
<?php
public function up()
{
	Schema::create('evenements', function (Blueprint $table) {
		$table->increments('id');
		$table->timestamps();
		$table->string('email', 100);
		$table->integer('number');
		$table->boolean('enabled');
		$table->date('created_at');
		$table->integer('id_art_category')->unsigned(); //needed to foreign keys
		$table->foreign('id_art_category')->references('id_category')->on('art_category');
	});
}
?>

<!-- Simple commands -->
<?php
use DB;
DB::insert('insert into student (name) values(?)',[$name]);
DB::update('update student set name = ? where id = ?',[$name,$id]);
DB::delete('delete from student where id = ?',[$id]);
$users = DB::select('select * from student');
$users[0]->email //retrieving elements
?>

<!-- ELOQUENT: ??? -->
Each table is represented by a class (that extend the model class)
Create this table: php artisan make:model Email
<?php
namespace App;
use Illuminate\Database\Eloquent\Model;
class Email extends Model
{
	protected $table = 'evenements'; //name of the associated table
	public $timestamps = false; //desactivate columns 'created_at' and 'updated at'
}
?>

----------------------------
------ CUSTOM CLASSES ------
----------------------------
place into /utils (needs to be created)
add it into composer.json
run composer dumpautoload
http://izwebtechnologies.com/2019/04/06/how-to-create-custom-class-in-laravel/


------------------------
---- AUTHENTICATION ----
------------------------
php artisan make:auth
	It creates views, a controller and add route. Go to /home and everything ready



----------------
----EXAMPLES----
----------------
Whole form with views for both get and form methods: https://openclassrooms.com/en/courses/3613341-decouvrez-le-framework-php-laravel/3616909-les-entrees
Upload of an image into a dedicated folder: https://openclassrooms.com/en/courses/3613341-decouvrez-le-framework-php-laravel/3617196-configuration-et-session
Whole forum with laravel https://www.flowkl.com/tutorial/web-development/simple-blog-application-in-laravel-7/

--------------------
----- DEBUGBAR -----
--------------------
<?php
use Debugbar;

Debugbar::info("this object: ", $object);
Debugbar::error('Error!');
Debugbar::warning('Watch out…');
Debugbar::addMessage('Another message', 'mylabel'); //can't display var
?>
